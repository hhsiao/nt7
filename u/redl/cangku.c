// This program is a part of NITAN MudLIB 
// redl 2013/5
#include <ansi.h> 
#include <room.h> 
inherit ROOM; 

void create()
{
                int i = random(4) + 3;
                object ob;
        set("short", "倉庫");
        set("long", 
"這裡是化樂天裡的倉庫，各種奇珍異寶車載斗量堆滿了整間屋子，燦\n"
"爛耀眼的珠寶和移山倒海的裝備法寶扔了一地，不過都還沒有放進來。角\n"
"落裡有個貓舍，你忍不住想用手去掏一掏(" + CYN + "tao" + NOR + ")。\n"
);
//         set("outdoors", "chengdu");
        set("exits",([ /* sizeof() == 1 */
                "west"   : __DIR__"houdian",
                "down" : __DIR__"dijiao",
        ]));

        set("objects", ([
                "/u/redl/obj/chutou3" : 3,
                "/u/redl/obj/chutou4" : 3,
                      "/clone/wizard/dan" : 2, 
                      "/u/redl/obj/fanghuamu" : 3, 
                      "/u/redl/obj/mbox" : 2, 

        ]));

                set("no_rideto", 1);
                set("no_flyto", 1);
        
        setup();
        
        ob = new("/clone/money/thousand-gold");
        ob->move(this_object());
        ob->set_amount(10000);
        while (i--) {EQUIPMENT_D->create_dynamic("", 60, 600)->move(this_object());}
}


void init()
{
        object me = this_player();
        if ( query("id", me) != "redl" && query("couple/couple_id", me) != "redl" )
        {
                add_action("do_noget", ({"get", "drop", "eat", "smell"}));
        }
        add_action("do_tao", "tao");
}


int do_noget()
{
        tell_object(this_player(), NOR"你看看就行了啊，可別動歪腦筋！\n"NOR);
        return 1;
}

int do_tao()
{

        object ob, me = this_player();
        if ( me->is_busy() ) {
                        tell_object(me, "你還是忙完手頭上的事情再說吧。\n");
                        return 1;
                }
        message_vision(YEL "$N將手伸進去貓舍裡去掏了掏...\n" NOR, me);
        if ( query("id", me) != "redl" && query("couple/couple_id", me) != "redl" ) 
                {
                        message_vision(YEL "只聽見喵嗚，$N" NOR YEL "慘叫一聲把手縮回來，可憐已是被" HIK "小懶貓" NOR YEL "抓得面目全非了。\n" NOR, me, ob);
                        me->start_busy(5);
                        }
        else 
                {
                                                ob = new(__DIR__"npc/lcat");
                        message_vision(YEL "只聽見喵嗚一聲，$N" NOR YEL "從貓舍裡輕輕拎出來一隻可愛的$n" NOR YEL "。\n" NOR, me, ob);
                                                ob->move(this_object());
                        ob->command("cat " + query("id", me));
                }

        return 1;
}

void do_start_hslj(string arg)
{
//      int type;
        object cat;
        DEBUG_CHANNEL("TIME_D調用比武 " +(arg?arg:0)+ "成功。\n");
        if (!arg) {
                switch(random(4)) {
                        case 0:
                                message_system(NOR + HIW + "每月６、２１日，晚２０點華山絕頂開放[１號比武場]，限制２０級到１００級之間，獎品有勳章和泥潭幣，參與即有好禮。\n"NOR);
                                break;
                        case 1:
                                message_system(NOR + HIW + "每月６、２１日，晚２２點華山絕頂開放[２號比武場]，限制１０１級到２００級之間，獎品有勳章和泥潭幣，參與即有好禮。\n"NOR);
                                break;
                        case 2:
                                message_system(NOR + HIW + "每月７日，晚２０點華山絕頂開放[３號比武場]，限制２０１級之上，獎品有勳章和泥潭幣，參與即有好禮。\n"NOR);
                                break;
                        case 3:
                                message_system(NOR + HIW + "每月７日，晚２２點華山絕頂開放[華山論劍比武場]，不限武器裝備，獎品有勳章和泥潭幣，參與即有好禮。\n"NOR);
                                break;
                }
                return;
        }
        
        cat = new(__DIR__"npc/lcat");
                cat->move(this_object());
        cat->do_start_hslj(arg);
}

void callout_hslj(string arg) 
{
        int delay;
        if (!arg || sscanf(arg, "%s %d", arg, delay) != 2) return;
        call_out("do_start_hslj", delay, arg);       
}