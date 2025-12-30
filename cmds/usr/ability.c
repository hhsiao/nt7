// This program is a part of NT MudLIB

#include <ansi.h>
#ifndef F_ABILITY;
#define F_ABILITY        "/adm/daemons/abilityd"
#endif

inherit F_ABILITY;
int main(object me, string arg)
{
        string id;
        int ab, n;
        int i, a_num, learned_ability;
        object ob;
        string arg1, myclass;

        MYGIFT_D->check_mygift(me, "newbie_mygift/ability");
        if( wizardp(me) )
        {
                if( arg && sscanf(arg, "-%s", id) == 1 )
                {
                        ob = present(id, environment(me));
                        if (!ob) ob = find_player(id);
                        if (!ob) ob = find_living(id);
                        if (!ob) return notify_fail("你要察看誰的能力？\n");
                } else
                        ob = me;
        } else
                ob = me;

        ab = query("ability", ob);

        learned_ability=query("learned_ability", ob);

        if( arg && ob == me )
        {
                if( !sscanf(arg, "+ %d", a_num) )
                        return notify_fail("提高能力的格式：ability + 能力名稱 \n");

                if( a_num < 1 || a_num > 50 )
                        return notify_fail("沒有此代碼的能力（請輸入1-35）\n");

                if( a_num < 21 )
                {
                        arg1 = bas_ability[a_num-1];

                        if( !valid_ability_improve(ob, arg1, 0) )
                                return notify_fail("你的經驗等級還不足以掌握更高的該項能力。\n");

                        if( !do_ability_cost(ob, arg1, 0) )
                                return notify_fail("你沒有足夠的能力點和潛能儲蓄來提高此項能力。\n");

                        improve_ability( ob, arg1, 0);
                        tell_object(ob, "該第"+ (a_num) + "能力提高完畢。\n");
                        return 1;
                }

                if( !stringp(myclass=query("family/family_name", ob)) )
                        return notify_fail("你無門無派，如何能夠領會門派武功的精髓？\n");

                if( !arrayp(fam_ability[myclass]) || (n = sizeof(fam_ability[myclass])) < a_num-20 )
                {
                         return notify_fail("OOPS，你所在的門派的此項特色還沒寫好耶。\n");

                } else
                {
                        arg1 = fam_ability[myclass][a_num-21];
                        if( !valid_ability_improve(ob, arg1, 1) )
                                return notify_fail("你的經驗等級還不足以掌握更高的該項能力。\n");

                        if( !do_ability_cost(ob, arg1, 1) )
                                return notify_fail("你沒有足夠的能力點儲蓄來提高此項能力。\n");

                        improve_ability(ob, arg1, 1);
                        tell_object(ob, "該第"+ (a_num) + "能力提高完畢。\n");
                }

                return 1;
        }


        write("\n");
        write(HIC    "序號              功效                      等級          升級點數\n"NOR);
        write(HIG "——————————————————————————————————\n" NOR);
        write(HIC"基本能力進階：\n\n"NOR);

        for(i=0; i<sizeof(bas_ability); i++)
                write(sprintf(WHT"("WHT"%3d"WHT")", (i+1)) + HIC"\t"+ get_ability_info(ob, bas_ability[i], 0) + NOR);
        write("\n");

        write(HIG "——————————————————————————————————\n" NOR);
        write(HIC"門派能力進階：\n\n"NOR);

        if( !stringp(myclass=query("family/family_name", ob)) )
                write("無門無派無特色。\n");
        /*
        else if( query("betrayer", ob) )
                write("你有叛師前科，無法領會新門派的精髓。\n");
        */
        else if( !arrayp(fam_ability[myclass]) )
                write("OOPS，你所在的門派的特色還沒寫好耶。\n");
        else
                for( i=0; i<30; i++ )
                {
                        if( i > sizeof(fam_ability[myclass])-1 ) break;
                        write(sprintf(WHT"("WHT"%3d"WHT")", (i+21)) + HIC"\t"+ get_ability_info(ob, fam_ability[myclass][i],1) + NOR);
                }

        write("\n");
        write(HIG "——————————————————————————————————\n" NOR);

        write(HIW"你現在總共獲得 "HIC + ab + NOR+HIW" 點能力。\n" NOR);
        write(HIW"你已經用去了 " RED+ learned_ability +NOR+HIW" 點能力，還剩下 "HIG+ (ab-learned_ability) + NOR+HIW" 點可供分配。\n" NOR);
        //write(HIG "——————————————————————————————————\n" NOR);
        write("\n\n");
        return 1;
}


int help(object me)
{
write(@HELP

----------------------------------------------------------------
指令格式 :     ability
----------------------------------------------------------------

ability         讓你知道你目前所學過的一切能力，
ability + n     提高第ｎ項能力的等級。

能力是泥潭遊戲中除經驗值、技能值以外提高自身的一個重要途徑。
相同經驗等級的，能力高的人會有更多的氣血，造成更大的傷害力，
或者可以有更高的學習效率。如何合理分配能力點是成為高手的一
大基本要求。

當你的人物等級升級而獲得能力點，就可以提高自身的各項能力了！
輸入ａｂｉｌｉｔｙ就可以看到一個清晰的列表。分兩大類，第一
類共有２０項，所有門派都可以修習，大多是提高基本屬性的；第
二類有五項，屬於門派武功的精髓所在，不同門派各有特色。

每項能力共分十級，每級的功效都有詳細說明。

該修習什麼呢？這就是由各個不同門派的特點或者個人喜好所決定
了。如果你想在戰鬥中持久，就多提高些增長精氣神的能力，如果
你要提高殺傷力，就提高些力量。。。。



能力點重置：
    玩家可以在泥潭商城處購買龍晶可用來重置已經分配好的能力點。
重置後，所有能力進階還原為能力點。第一次重置能力會消耗一個龍
晶；之後每重置一次，會再額外消耗一個龍晶；第25次及之後的重置
將不會再額外增加消耗，固定每次25個龍晶。

----------------------------------------------------------------
HELP
    );

        MYGIFT_D->check_mygift(me, "newbie_mygift/ability");
        return 1;
}
