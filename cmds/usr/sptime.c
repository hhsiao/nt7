// time.c
#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg) {
    int cur_time = time();
    object ob;
    string sp = "";

    if(!wizardp(me) && cur_time - query_temp("last_service", me)<5 )
        return notify_fail("系統氣喘噓地嘆道：慢慢來 ....\n");

    set_temp("last_service", cur_time, me);

    if(arg && wizardp(me) )
    {
        ob = present(arg, environment(me));
        if (!ob) ob = find_player(arg);
        if (!ob) ob = find_living(arg);
        if (!ob) return notify_fail("你要察看誰的狀態？\n");
    } else
    ob = me;

    if(MEMBER_D->is_valid_member(ob) )
        sp += sprintf(HIG + (ob == me ? "你" : ob->name()) + HIG "可用來離線練功時間還有 " NOR + HIY "無限制\n" NOR);
    else
    {
        if(query("online_time", ob) / 3<query("offline_time", ob) )
            set("offline_time", query("online_time", ob) / 3, ob);
        sp += sprintf(HIG + (ob == me ? "你" : ob->name()) + HIG "可用來離線練功時間還有 " NOR + HIY "%s\n" NOR,
            time_period(query("online_time", ob) / 3 - query("offline_time", ob)));
    }
    sp += sprintf(HIG + (ob == me ? "你" : ob->name()) + HIG "下線保留物品時間還剩下 " NOR + HIW "%s\n" NOR,
        (query("srv/quit_save", ob) - time()) > 0 ? time_period(query("srv/quit_save", ob) - time()) : "零秒");
    sp += sprintf(HIG + (ob == me ? "你" : ob->name()) + HIG "離線原地登陸時間還剩下 " NOR + HIW "%s\n" NOR,
        (query("srv/start_room", ob) - time()) > 0 ? time_period(query("srv/start_room", ob) - time()) : "零秒");
    sp += sprintf(HIG + (ob == me ? "你" : ob->name()) + HIG "乾坤袋增容量時間還剩下 " NOR + HIW "%s\n" NOR,
        (query("srv/qiankun_volume", ob) - time()) > 0 ? time_period(query("srv/qiankun_volume", ob) - time()) : "零秒");
    sp += sprintf(HIG + (ob == me ? "你" : ob->name()) + HIG "九頭蛇領地權時間還剩下 " NOR + HIW "%s\n" NOR,
        (query("srv/enter_jtshe", ob) - time()) > 0 ? time_period(query("srv/enter_jtshe", ob) - time()) : "零秒");
    sp += sprintf(HIG + (ob == me ? "你" : ob->name()) + HIG "師門飛鴿傳書時間還剩下 " NOR + HIW "%s\n" NOR,
        (query("srv/quest_letter", ob) - time()) > 0 ? time_period(query("srv/quest_letter", ob) - time()) : "零秒");
    sp += sprintf(HIG + (ob == me ? "你" : ob->name()) + HIG "今天的雙倍經驗時間還餘 " NOR + HIW "%s\n" NOR,
        time_period(query("time_reward/quest", ob)));
    sp += sprintf(HIG + (ob == me ? "你" : ob->name()) + HIG "今天的高效練功時間還餘 " NOR + HIM "%s\n" NOR,
        time_period(query("time_reward/study", ob)));

    me->start_more(sp);
    return 1;
}

int help(object me) {
    write(@HELP
指令格式: service

這個指令告訴你購買的各種服務到期的時間。

HELP
    );
    return 1;
}
