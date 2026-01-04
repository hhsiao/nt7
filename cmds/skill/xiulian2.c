
inherit F_CLEAN_UP;

#include <ansi.h>

#define SK_ID           "yinyang-shiertian"
#define SK_NAME         "陰陽九轉十二重天"

int outing(object me, string FLAG_ID, string FLAG_NAME, int DIFF);
int halt_outing(object me);

void create() { seteuid(getuid()); }

int main(object me, string arg) {
    object where;
    string FLAG_ID, FLAG_NAME;
    int DIFF, SK_LV;

    seteuid(getuid());
    where = environment(me);

    if (! arg)return notify_fail("指令格式：xiulian <境界>，請參見相關help文件。\n");

    if (arg != "yinyang" && arg != "qiankun" && arg != "shier")
        return notify_fail("指令格式：xiulian <境界>，請參見相關help文件。\n");

    if (arg == "yinyang")
    {
        FLAG_ID = "yinyang-shiertian/yinyang";
        FLAG_NAME = "陰陽境界";
        if (me->query(FLAG_ID))
            return notify_fail("你已經修煉過" + FLAG_NAME + "了，沒有必要再來一遍吧！\n");
        SK_LV = 380;
        DIFF = 100 + 3 * me->query(FLAG_ID);
    }
    else
        if (arg == "qiankun")
    {
        if (! me->query("yinyang-shiertian/yinyang"))
            return notify_fail("必須修煉成功陰陽境界後方能修煉乾坤境界。\n");

        FLAG_ID = "yinyang-shiertian/qiankun";
        if (me->query(FLAG_ID) >= 9)
            return notify_fail("你已經修煉成乾坤境界了，沒必要再來一遍吧！\n");

        // 九十六小時內不得再次修煉
        if (time() - me->query("last_xiulian_end") < 96 * 3600)
            return notify_fail("離上次修煉完成還不到九十六小時，不能再次修煉乾坤境界，否則你將走
火入魔。\n");

        FLAG_NAME = "乾坤境界第" + chinese_number(me->query(FLAG_ID) + 1) + "層";
        SK_LV = 480;
        DIFF = 100 + 5 * me->query(FLAG_ID);
    }
    else    // 12重天境界
    {
        if (me->query("yinyang-shiertian/qiankun") < 9)
            return notify_fail("必須修煉成功乾坤境界後方能修煉十二重天境界。\n");

        FLAG_ID = "yinyang-shiertian/shier";
        if (me->query(FLAG_ID) >= 12)
            return notify_fail("你已經修煉成十二重天境界了，沒必要再來一遍吧！\n");

        // 一百二十小時內不得再次修煉
        if (time() - me->query("last_xiulian_end") < 120 * 3600)
            return notify_fail("離上次修煉完成還不到一百二十小時，不能再次修煉十二重天境界，否則
你將走火入魔。\n");

        FLAG_NAME = "十二重天境界第" + chinese_number(me->query(FLAG_ID) + 1) + "層";
        SK_LV = 600;
        DIFF = 100 + 6 * me->query(FLAG_ID);
    }
    if (me->query_skill(SK_ID, 1) < SK_LV)
        return notify_fail("你" SK_NAME "等級不夠，無法修煉！\n");

    if (! where->query("no_fight"))
        return notify_fail("在這裡修煉？不太安全吧？\n");

    if (! where->query("sleep_room"))
        return notify_fail("你得找一個能夠休息的地方閉關修煉修行。\n");

    if (me->is_busy())
        return notify_fail("你現在正忙著呢。\n");

    if (me->query("potential") - me->query("learned_points") < 10000)
        return notify_fail("你的潛能不夠，沒法閉關修行。\n");

    if ((int)me->query("qi") * 100 / me->query("max_qi") < 99)
        return notify_fail("你現在的氣太少了，無法靜心閉關。\n");

    if ((int)me->query("jing") * 100 / me->query("max_jing") < 99)
        return notify_fail("你現在的精太少了，無法靜心閉關。\n");

    if ((int)me->query("max_jingli") < 2000)
        return notify_fail("你覺得精力修為頗有不足，看來目前還難以修煉。\n");

    if ((int)me->query("jingli") * 100 / me->query("max_jingli") < 99)
        return notify_fail("你現在的精力太少了，無法靜心閉關修煉。\n");

    message_vision("$N盤膝坐下，開始冥神運功，閉關修行。\n", me);
    me->set("startroom", base_name(where));
    me->set("doing", "xiulian");
    CLOSE_D->user_closed(me);
    me->start_busy(bind((:call_other, __FILE__, "outing", me, FLAG_ID, FLAG_NAME, DIFF :), me),
        bind((:call_other, __FILE__, "halt_outing": ), me));

    tell_object(me, HIC "你開始閉關苦修，試圖修煉" + FLAG_NAME + "。\n" NOR);

    /*
     * CHANNEL_D->do_channel(this_object(), "rumor",
     * sprintf("%s%s(%s)開始閉關苦修，試圖修煉" + FLAG_NAME + "。",
     * ultrap(me) ? "大宗師" : "",
     * me->name(1), me->query("id")));
     */
    return 1;
}


int continue_outing(object me) {
    me->start_busy(bind((:call_other, __FILE__, "outing": ), me),
        bind((:call_other, __FILE__, "halt_outing": ), me));
    CLOSE_D->user_closed(me);
    tell_object(me, HIR "\n你繼續閉關苦修，試圖突破新的境界...\n" NOR);
    return 1;
}

private void stop_outing(object me) {
    CLOSE_D->user_opened(me);
    if (! interactive(me))
    {
        me->force_me("chat* sigh");
        call_out("user_quit", 0, me);
    }
}

int outing(object me, string FLAG_ID, string FLAG_NAME, int DIFF) {
    string msg;

    if (me->query("potential") <= me->query("learned_points"))
    {
        tell_object(me, "你潛能耗盡，沒有辦法繼續下去了。\n");
        message_vision("$N睜開雙目，緩緩吐了一口氣，站了起來。\n", me);
        CLOSE_D->user_opened(me);
        /*
         * CHANNEL_D->do_channel(this_object(), "rumor",
         * sprintf("聽說%s(%s)閉關修煉結束，似乎沒有什麼成果。",
         * me->name(1), me->query("id")));
         */
        if (! interactive(me))
        {
            me->force_me("chat* sigh");
            call_out("user_quit", 0, me);
        }

        return 0;
    }

    me->add("learned_points", 1);

    // if (random(DIFF) && ! wizardp(me))return 1;

    if ((random(3) == 1 && random(DIFF * 100) < me->query_con()) || wizardp(me) && FLAG_ID != "yinyang-shiertian/shier")
    {
        // 重啟後FLAG_ID = 0
        if (! FLAG_ID)
        {
            if (! interactive(me))
            {
                me->force_me("chat* sigh");
                call_out("user_quit", 0, me);
            }
            return 0;
        }

        // 消耗輪迴點
        if (FLAG_ID == "yinyang-shiertian/yinyang" && me->query("scborn/cur_lunhui_point") < 2 && ! me->query("thborn/ok"))
        {
            tell_object(HIR "你的輪迴點不足。\n" NOR);
            CLOSE_D->user_opened(me);
            if (! interactive(me))
            {
                me->force_me("chat* sigh");
                call_out("user_quit", 0, me);
            }
            return 0;
        }
        if (FLAG_ID == "yinyang-shiertian/qiankun" && me->query("scborn/cur_lunhui_point") < 3 && ! me->query("thborn/ok"))
        {
            tell_object(HIR "你的輪迴點不足。\n" NOR);
            CLOSE_D->user_opened(me);
            if (! interactive(me))
            {
                me->force_me("chat* sigh");
                call_out("user_quit", 0, me);
            }
            return 0;
        }
        if (FLAG_ID == "yinyang-shiertian/shier" && me->query("scborn/cur_lunhui_point") < 4 && ! me->query("thborn/ok"))
        {
            tell_object(HIR "你的輪迴點不足。\n" NOR);
            CLOSE_D->user_opened(me);
            if (! interactive(me))
            {
                me->force_me("chat* sigh");
                call_out("user_quit", 0, me);
            }
            return 0;
        }

        message_vision(HIY "只見$N" HIY "頭上現出萬朵金蓮，光"
            "華四射，一時間麝香撲鼻、氤氳遍地！\n" NOR, me);
        tell_object(me, HIW "你覺得精力源源而生，忽然心如止水，如身出"
            "天際，無源無盡、登時大徹大悟。\n" NOR);
        tell_object(me, HIG "恭喜你，修煉成 " + FLAG_NAME + " 。\n" NOR);

        me->add(FLAG_ID, 1);
        if (! me->query("thborn/ok"))
        {
            // 消耗輪迴點
            if (FLAG_ID == "yinyang-shiertian/yinyang")
            {

                me->add("scborn/cur_lunhui_point", -2);
                me->save();
            }
            if (FLAG_ID == "yinyang-shiertian/qiankun" && me->query("yinyang-shiertian/qiankun") == 9)
            {
                me->add("scborn/cur_lunhui_point", -3);
                me->save();
            }
            if (FLAG_ID == "yinyang-shiertian/shier" && me->query("yinyang-shiertian/shier") == 12)
            {
                me->add("scborn/cur_lunhui_point", -4);
                me->save();
            }
        }
        /*
         * CHANNEL_D->do_channel(this_object(), "rumor",
         * sprintf("聽說%s(%s)經過閉關苦修，終"
         * "於參悟出其中奧妙，修煉出" + FLAG_NAME + "。",
         * me->name(1), me->query("id")));
         */
        CHAR_D->setup_char(me);
        stop_outing(me);
        return 0;
    }

    switch (random(4))
    {
    case 0:
        msg = "你閉目凝神，試圖進入無我境界。\n";
        break;

    case 1:
        msg = "你試圖將元神與肢體分離，融入" + SK_NAME + "無上境界。\n";
        break;

    case 2:
        msg = "你試圖將元神逼出七竅，然後周遊四處復又收回。\n";
        break;

    default:
        msg = "你緩緩呼吸吐納，將空氣中水露皆收為己用。\n";
        break;
    }

    tell_object(me, msg);
    return 1;
}

int halt_outing(object me) {
    CLOSE_D->user_opened(me);
    tell_object(me, "你中止了閉關修煉。\n");
    message_vision(HIY "$N" HIY "輕輕嘆了一口氣，緩緩的睜開眼。\n\n" NOR, me);
    me->add("potential", (me->query("learned_points") - me->query("potential")) / 2);
    /*
     * CHANNEL_D->do_channel(this_object(), "rumor", "聽說" + me->name(1) +
     * "閉關修煉中途突然復出。");
     */
    return 1;
}

private void user_quit(object me) {
    if (! me || interactive(me))
        return;

    me->force_me("quit");
}

int help(object me) {
    write(@HELP
指令格式 : xiulian [境界]

該指令可使你修煉某些特殊境界。

HELP );
    return 1;
}
