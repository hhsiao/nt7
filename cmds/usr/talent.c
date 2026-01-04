// This program is a part of NT MudLIB

#include <ansi.h>
#ifndef F_ABILITY;
#define F_ABILITY        "/adm/daemons/abilityd"
#endif

inherit F_ABILITY;
int main(object me, string arg) {
    string id;
    int ab;
    int i, a_num, learned_energy;
    object ob;
    string arg1;
    int level;

    MYGIFT_D->check_mygift(me, "newbie_mygift/talent");
    if(wizardp(me) )
    {
        if(arg && sscanf(arg, "-%s", id) == 1 )
        {
            ob = present(id, environment(me));
            if (!ob) ob = find_player(id);
            if (!ob) ob = find_living(id);
            if (!ob) return notify_fail("你要察看誰的天賦技能？\n");
        } else
        ob = me;
    } else
    ob = me;

    ab = query("energy", ob);

    learned_energy = query("learned_energy", ob);

    if(arg && ob == me )
    {
        if(!sscanf(arg, "+ %d", a_num) )
            return notify_fail("提高天賦技能的格式：talent + 天賦技能代號 \n");

        if(a_num < 1 || a_num > 32 )
            return notify_fail("沒有此代碼的天賦技能（請輸入1-30）\n");

        if(a_num < 33 )
        {
            arg1 = talent_ability[a_num - 1];
            level = query("yuanshen_level", ob);

            if(a_num > (level / 10 + 1) * 3 )
                return notify_fail("你的元神境界還不足以掌握更高的天賦技能。\n");

            if(!valid_ability_improve(ob, arg1, 2) )
                return notify_fail("你的元神境界還不足以掌握更高的該項能力。\n");

            if(!do_ability_cost(ob, arg1, 2) )
                return notify_fail("你沒有足夠的天賦點儲蓄來提高此項能力。\n");

            improve_ability(ob, arg1, 2);
            tell_object(ob, "該第"+ (a_num) + "天賦技能提高完畢。\n");
            return 1;
        }

        return 1;
    }


    write("\n");
    write(HIY + (ob==me?"你":ob->query_idname()) + HIY"掌握的天賦技能如下\n"NOR);
    write(HIG"——————————————————\n" NOR);
    write(HIC    "序號              功效                                                等級          升級點數\n"NOR);
    write(HIG "——————————————————————————————————————————————\n" NOR);

    for(i = 0; i<sizeof(talent_ability); i++)
        write(sprintf(WHT"("WHT"%3d"WHT")", (i + 1)) + HIC"\t"+ get_ability_info(ob, talent_ability[i], 2) + NOR);
    write("\n");

    write(HIG "——————————————————————————————————————————————\n" NOR);

    write(HIW"你現在總共獲得 "HIC + ab + NOR + HIW" 點天賦點。\n" NOR);
    write(HIW"你已經用去了 " RED + learned_energy + NOR + HIW" 點天賦點，還剩下 "HIG + (ab - learned_energy) + NOR + HIW" 點可供分配。\n" NOR);
    //write(HIG "——————————————————————————————————————————————\n" NOR);
    return 1;
}


int help(object me) {
    write(@HELP

[0;1;37m----------------------------------------------------------------[0m
[0;1;36m指令格式 :     talent [0m
[0;1;37m----------------------------------------------------------------[0m

talnet         讓你知道你目前所掌握的一切天賦技能，
talent + n     提高第ｎ項天賦技能的等級。

能力點重置：
    玩家可以在泥潭商城處購買龍晶可用來重置已經分配好的天賦點。
重置後，所有天賦技能還原為天賦點。第一次重置天賦會消耗一個龍
晶；之後每重置一次，會再額外消耗一個龍晶；第25次及之後的重置
將不會再額外增加消耗，固定每次25個龍晶。

[0;1;37m----------------------------------------------------------------[0m
HELP
    );

    MYGIFT_D->check_mygift(me, "newbie_mygift/talent");
    return 1;
}
