// This program is a part of NITAN MudLIB 
// redl 2013/9
#include <ansi.h> 
#include <room.h> 
inherit __DIR__"normal.c"; 

void create()
{
        set("short", "藥圃");
        set("long", 
"這是藥圃，各種奇珍異草在這裡不分季節地競相開放，傳說偶爾大運的\n"
"人可以在這裡拾到靈草。\n"
);
                set("outdoors", "dongtian");
                set("exits",([ /* sizeof() == 1 */
                        "north" : __DIR__"liandanfang",
                        "east" : __DIR__"caidi",
                        "west" : __DIR__"shanlu2",
                ]));

        set("objects", ([ 
                "/d/shenlong/obj/hua4" : (!random(5) ? 1 : 0),
        ])); 

        set("no_steal",1);
        set("no_beg",1);         
                set("no_rideto", 1);
                set("no_flyto", 1);
        set("no_drift", 1);
        set("no_sleep_room", 1); 
        set("max_carry_user" ,20);
        
        setup();
}




