
// upblood
/*
 * 血脈分為十級：覺醒 通脈 易筋 洗髓 換骨 脫胎 靈身 仙體 神脈 聖尊
 * 血脈的修煉需要材料如下：
 * 覺醒：每次消耗一顆血脈丹（一品），修煉一次增加進度5%
 * 通脈：每次消耗一顆血脈丹（二品），修煉一次增加進度5%
 * 易筋：每次消耗一顆血脈丹（三品），修煉一次增加進度5%
 * 洗髓：每次消耗一顆血脈丹（四品），修煉一次增加進度5%
 * 換骨：每次消耗一顆血脈丹（五品），修煉一次增加進度4%
 * 脫胎：每次消耗一顆血脈丹（六品），修煉一次增加進度4%
 * 靈身：每次消耗一顆血脈丹（七品），修煉一次增加進度4%
 * 仙體：每次消耗一顆血脈丹（八品），修煉一次增加進度3%
 * 神脈：每次消耗一顆血脈丹（九品），修煉一次增加進度3%
 * 聖尊：每次消耗一顆血脈丹（十品），修煉一次增加進度3%
 * 攻擊技能．天怒神罰，代天行罰
 * 血脈修煉完成第一重“覺醒”，自動領悟主動攻擊技能——“天怒神罰”。
 * 血脈等級的提高可大幅度提高玩家的最大內力、最大精力上限，同時大幅度提高玩家的最大氣血和精氣，以及攻擊力和防禦力。
 */

#include <ansi.h>

inherit F_CLEAN_UP;

int help(object me);
mapping xuemai = ([
    "stealth": "仙體",
    "wisdom": "人體",
    "ghost": "鬼體",
    "demon": "魔體",
    "nopoison": "怪體",
    "monster": "妖體"
    ]);

void create() { seteuid(getuid()); }

int main(object me, string arg) {
    int points, added, level, i;
    mapping my, spe_data;
    string msg, skill, sname;
    object dan;
    string *spe_skill = ({
        "monster", "nopoison", "demon", "ghost", "wisdom", "stealth"
    });

    seteuid(getuid());

    if(me->is_busy() || me->is_fighting() )
        return notify_fail(BUSY_MESSAGE);

    if(!arg || arg == "" )
        return help(me);

    if(arg == "reset" )
    {
        delete("xuemai_level", me);
        delete("xuemai", me);
        delete("xuemai_skill", me);
        for(i = 0; i<sizeof(spe_skill); i++ )
        {
            if(query("special_skill/"+spe_skill[i], me) )
                delete("special_skill/"+spe_skill[i], me);
        }
        write(HIR "你取消了你的血脈傳承屬性。\n" NOR);
        return 1;
    }

    if(arg == "check" )
    {
        if(query("xuemai_skill", me) )
        {
            write(HIR "你的血脈傳承屬性是："+ xuemai[query("xuemai_skill", me)] + "。\n" NOR);
            return 1;
        }
        return notify_fail("你當前沒有血脈屬性。\n");
    }




    if(!objectp(dan = present(arg, me)) )
        return notify_fail("你身上沒有血脈丹，無法提升血脈。\n");

    if(!dan->is_xuemai_dan() )
        return notify_fail("你無法使用它來提升血脈。\n");

    level = query("xuemai_level", me) + 1;
    if(level > 10 )
        return notify_fail("你的血脈已經達到最高境界了，無需繼續提升了。\n");

    if(query("level", dan) < level )
        return notify_fail("你身上的血脈丹品級過低，無法提升血脈。\n");

    if(!query("jingmai/finish", me) )
        return notify_fail("你需要先打通你全身大小周天經脈。\n");

    if((int)me->query_skill("force", 1) < 2000 )
        return notify_fail("你的內功修為不足，沒法提升自身血脈。\n");

    if(query("potential", me) - query("learned_points", me) < 10000000 )
        return notify_fail("你的潛能不夠，沒法提升自身血脈。\n");

    if(query("qi", me)*100 / query("max_qi", me)<90 )
        return notify_fail("你現在的氣太少了，無法靜心提升血脈。\n");

    if(query("jing", me)*100 / query("max_jing", me)<90 )
        return notify_fail("你現在的精太少了，無法靜心提升血脈。\n");

    if(query("max_neili", me) < 100000 )
        return notify_fail("你覺得內力頗有不足，看來目前還難以進行血脈的提升。\n");

    if(query("neili", me)*100 / query("max_neili", me) < 90 )
        return notify_fail("你現在的內力太少了，無法靜心提升血脈。\n");

    addn("learned_points", 10000000, me);
    dan->add_amount(-1);
    if(dan->query_amount() < 1 )
        destruct(dan);

    message_vision(HIW "只見$N" HIW "頭上白霧騰騰、渾身如同籠罩在雲中。\n" NOR, me);

    //全身血液煥然一新，所謂是練髓如霜，練血汞漿。脫胎換骨，伐毛洗髓。

    switch (level)
    {
    case 1:
        msg = HIR "你周身血液宛如火焰一樣熾熱，血液翻滾著。血脈中一些奇特的東西正在逐漸的甦醒，你感受到了\n"
        "一種前所未有的強橫力量正逐漸的從你身體每一個角落浸潤出來。\n" NOR;
        break;

    case 2:
    case 3:
    case 4:
        msg = HIB "你的血液被凍結了，然後變成了流動的冰霜，迅速的沖刷著你的身體。從骨髓到皮膚，大量的汙垢\n"
        "雜質不斷的被暴力排斥出來。你的骨髓逐漸的轉變著顏色，變得更加潤紅，更加的深邃。\n" NOR;
        break;

    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
        msg = HIR "你的血液開始沸騰，你的骨髓中開始不斷產生巨量的血液，而這些血液中的細胞開始瘋狂的吞噬和\n"
        "合併，大量奇妙的氣息從你的血液中不斷的滋生，漸漸的你的血液變得越來越粘稠，每一滴血液中\n"
        "蘊藏的能量和營養越來越強大，光澤也越來越奪目瑰麗。\n" NOR;
        break;

    default:
        msg = HIY "你原本紅色的血液，已經徹底轉化為淡金色。如果將你的血液盛放在容器中，那將會是一顆淡金色\n"
        "的寶珠，因為本體蘊藏的龐大能量不斷外洩，這顆寶珠如果不加以控制，它將會滿天亂飛，並且因\n"
        "為它龐大的密度而對四周的物體造成可怕的破壞，甚至空間塌陷。\n" NOR;
        break;
    }

    tell_object(me, msg);

    points = query("xuemai/points", me);

    if(level < 5 ) added = 5;
    else if(level < 8) added = 4;
    else added = 3;

    points += added;
    set("xuemai/points", points, me);

    if(points >= 100 )
    {
        addn("xuemai_level", 1, me);
        delete("xuemai/points", me);


        if(query("xuemai_level", me) == 1 )
        {
            skill = spe_skill[random(sizeof(spe_skill))];
            set("xuemai_skill", skill, me);
            tell_object(me, HIM "你終於喚醒了你的遠古血脈傳承-->"+xuemai[skill] + "。\n" NOR);
            tell_object(me, HIC "你如果對血脈傳承屬性不滿意，可以upblood reset來重新獲取血脈傳承。\n" NOR);
        }
        else if(query("xuemai_level", me) == 10 )
        {
            // 取消原先元神獲得的血脈技能
            for(i = 0; i<sizeof(spe_skill); i++ )
            {
                if(query("special_skill/"+spe_skill[i], me) )
                    delete("special_skill/"+spe_skill[i], me);
            }
            my = me->query_entire_dbase();
            skill = query("xuemai_skill", me);
            sname = SPECIAL_D(skill)->name();

            spe_data = ([ skill : 1 ]);
            my["special_skill"] += spe_data;

            tell_object(me, HIM "你成功的激活了血脈力量，掌握了血脈技能-->"+sname + "。\n" NOR);
        }
        else
            tell_object(me, HIM "你的血脈等級（品級）提升了。\n" NOR);

        CHAR_D->setup_char(me);
    }

    me->start_busy(1);
    return 1;
}


int help(object me) {
    write(@HELP
指令格式 : upblood <xuemai dan1> 提升血脈的品級
           upblood reset         重新覺醒血脈傳承
           upblood check         查詢你的當前血脈屬性

修煉提升血脈的等級，喚醒血脈技能。

HELP );
    return 1;
}
