// copyitem.c
// by Lonely

#include <ansi.h>

inherit F_CLEAN_UP;

protected int copy_stats(object me, object ob, string stats);
int help();

int main(object me, string arg)
{
        object ob;
        object tob;
        string stats, who, target;

        if (! SECURITY_D->valid_grant(me, "(admin)"))
                return 0;

        if (! arg)
        {
                help();
                return 1;
        }

        if (sscanf(arg, "%s from %s to %s", stats, who, target) == 3)
        {
                if (! objectp(tob = present(target, environment(me))) &&
                    ! objectp(tob = present(target, me)))
                        return notify_fail("你眼前沒有 " + target + " 這個物件。\n");
        } else
        {
                help();
                return 1;
        }

        if (! objectp(ob = present(who, environment(me))) &&
            ! objectp(ob = present(who, me)))
                return notify_fail("你眼前沒有 " + who + " 這個物件。\n");

        if (ob == tob)
                return notify_fail("不需要複製吧。\n");

        log_file("static/copyitem", sprintf("%s %s copy %s(%s)'s stats to %s(%s).\n",
                                             log_time(), log_id(me),
                                             ob->name(1),query("id", ob),
                                             tob->name(1), query("id", tob)));
        copy_stats(tob, ob, stats);
        message_vision(HIM + me->name(1) + HIM "口中唸唸有詞，只見一道紅光籠罩了$N"
                       HIM "和$n" HIM "。\n" NOR, tob, ob);
        return 1;
}

protected int copy_stats(object me, object ob, string stats)
{
        mapping your;
        mapping my;

        your = ob->query_entire_dbase();
        my = me->query_entire_dbase();
        
        if ( stats == "all" )
        {
                if (! undefinedp(your["weapon_prop"]))
                        my["weapon_prop"] = your["weapon_prop"];
                if (! undefinedp(your["armor_prop"]))
                        my["armor_prop"] = your["armor_prop"];
                if (! undefinedp(your["ultimate"]))
                        my["ultimate"] = your["ultimate"];
                if (! undefinedp(your["enchase"]))
                        my["enchase"] = your["enchase"];                        
                if (! undefinedp(your["insert"]))
                        my["insert"] = your["insert"];
                if (! undefinedp(your["magic"]))
                        my["magic"] = your["magic"];      
                if (! undefinedp(your["mod_level"]))
                        my["mod_level"] = your["mod_level"];                             
                if (! undefinedp(your["mod_name"]))
                        my["mod_name"] = your["mod_name"];
                if (! undefinedp(your["mod_mark"]))
                        my["mod_mark"] = base_name(me);          
                if (! undefinedp(your["qianghua"]))
                        my["qianghua"] = your["qianghua"];                                    
                if (! undefinedp(your["qiling"]))
                        my["qiling"] = your["qiling"];                                                                                          
                if (! undefinedp(your["rare"]))
                        my["rare"] = your["rare"]; 
                if (! undefinedp(your["status"]))
                        my["status"] = your["status"]; 
                if (! undefinedp(your["quality_level"]))
                        my["quality_level"] = your["quality_level"]; 
                if (! undefinedp(your["combat"]))
                        my["combat"] = your["combat"];                         
                if (! undefinedp(your["forge"]))
                        my["forge"] = your["forge"]; 
                if (! undefinedp(your["owner"]))
                        my["owner"] = your["owner"];                         
                
                return 1;
        }
        
        if (! undefinedp(your[stats]))
                my[stats] = your[stats];
 
        return 1;
}

int help()
{
        write(@TEXT
指令格式：copyitem <stats> from <對象> [to <目的對象>]

這個指令讓你複製對象的狀態。

該命令在可以被授權使用的信息包括：me、wizard、all。
TEXT );
        return 1 ;
}

