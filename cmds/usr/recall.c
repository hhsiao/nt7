// recall.c
// created by lonely@nitan2

#include <ansi.h>
inherit F_CLEAN_UP;

int help(object me);

int main(object me, string arg)
{
        string file;
        string str;
        object ob;
        object dtling;
 
        if (! environment(me)) 
                return 0; 

        if (! arg || (arg != "back" && arg != "dt" && 
            arg != "home" && sscanf(arg, "%s %s", arg, str) != 2))
                return help(me);
                               
        if (me->is_busy())
                return notify_fail("你正忙著呢。\n");

        if (me->is_fighting())
                return notify_fail("你現在正在戰鬥！\n"); 

        if (me->is_ghost()) 
                return notify_fail("等你還了陽再說吧。\n"); 
                
        if (me->is_in_prison())   
                return notify_fail("你正在做牢呢。\n");

        if( query("doing", me) )
                return notify_fail("你還想幹什麼？！\n");
                
        if( query("no_magic", environment(me)) )
                return notify_fail("你發現這裡不可以進行空間穿越！\n"); 
        
        if (arg == "back" || arg == "home" || arg == "dt")
        {
                if( query_temp("warquest/party", me) )
                        return notify_fail("你還想在戰爭中使用？！\n");

                if (present("biao huo", me))
                        return notify_fail("你身上帶著鏢銀，不能施展！\n");

                if( sscanf(base_name(environment(me)), "/d/register/%*s") )
                        return notify_fail("你還沒有出生呢，不能施展！\n");

                if( sscanf(base_name(environment(me)), "/d/newbie/%*s") )
                        return notify_fail("你在古村中，不能施展！\n");
                
                if( arg == "back" )
                        file = "/d/city/kedian";
                else if( arg == "dt" ) {
                                dtling = query_temp("handing", me);
                                if (!dtling || query("dt_value", dtling)!=3)
                                        return notify_fail("你手裡沒有拿(hand)著玉質的洞天仙府令！\n");
                                if (sscanf(base_name(environment(me)),"/d/dongtian/%*s"))
                                        return notify_fail("你不能從一個洞天裡跳到另一個洞天！\n");
                                file = replace_string(base_name( dtling ), "lingpai3", "") + "houshan";
                }
                else
                        file = query("private_room/entry", me);
                
                if( !file ) return notify_fail("你還沒有住房呢！\n");
                
                if (base_name(environment(me)) == file)
                        return notify_fail("你已經在這裡了。\n");
                        
                if (! get_object(file))
                        return notify_fail("你感覺到似乎有什麼不對勁！\n");

                message("vision", NOR + me->name() + "舉起" + ((arg == "dt") ? (query("name", dtling) + NOR) : "右手") + 
                                "在面前極速畫了一個圓，竟劃破了面前的"
                        "空間，\n只見圓內的空間真空將" + me->name() + "給吸了進去。\n" + NOR,
                        environment(me), ({me}));
                
                tell_object(me, "你從某個角落空間裂縫中鑽出。\n");

                me->move(file);
                message("vision", me->name() + "從某個角落空間裂縫中鑽出。\n",
                        environment(me), ({me}));

                                if (arg == "dt" && !random(6)) {
                                        message_vision(append_color(NOR "$N" NOR "手裡的$n" NOR "喀喇一聲碎裂散掉了...\n\n" NOR, HIY), me, dtling);
                                        destruct(dtling);
                                }

                MYGIFT_D->check_mygift(me, "newbie_mygift/recall");
                return 1;
        }
                                       
        else return help(me);
        return 1;
}

int help(object me)
{
 write(@HELP
指令格式 : recall back | home | dt
回到揚州客店的指令為 < recall back >。
回到住房的指令為 < recall home >。
回到洞天的指令為 < recall dt >。
HELP
    );
    return 1;
}




