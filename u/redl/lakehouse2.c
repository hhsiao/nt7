// This program is a part of NITAN MudLIB 
// redl 2013/5
#include <ansi.h> 
#include <room.h> 
inherit ROOM; 

void create()
{
        set("short", "木屋內");
        set("long", 
"這是間看上去十分舒適的大屋子，室內古樸的傢俱和恰當的陳設，顯\n"
"出曾有人幸福生活過的痕跡。明亮的窗戶外只見幾片枯葉飛過，忽聞寒鴉\n"
"從屋頂外傳來呱啊地一聲驚歎。\n"
);
         set("exits",([ /* sizeof() == 1 */
                 "out" : __DIR__"lakehouse",
         ]));

        set("objects", ([
//                "/u/redl/obj/mbox" : 1,
        ]));

        set("sleep_room", 1);
        set("loving_room", 1);
        set("no_fight", 1);

                set("no_rideto", 1);
                set("no_flyto", 1);
        
        setup();
}

void init()
{
        object me = this_player();
        if ( query("id", me) != "redl" && query("couple/couple_id", me) != "redl" )
        {
                        message_vision(YEL "一股微風吹過，把$N吹到了室外。\n" NOR, me);
                        me->move(__DIR__"lakehouse");
                        return;
        }
}




