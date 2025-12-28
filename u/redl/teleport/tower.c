// This program is a part of NITAN MudLIB 
// redl 2013/9
#include <ansi.h> 
#include <room.h> 
inherit __DIR__"normal.c"; 

void create()
{
        set("short", "鐵塔之頂");
        set("long", 
"這是開封鐵塔尖尖的頂部，幾個模糊的黑影正靜靜趴伏在塔的周\n"
"圍各簷角上，緊張地窺視著塔裡的情況。\n"
);
                set("outdoors", "yangzhou");
                set("exits",([ /* sizeof() == 1 */
                        "out" : __DIR__"teleport",
                ]));

        set("no_dazuo",1);
        set("no_kill",1);
        set("no_fight",1);
        set("no_steal",1);
        set("no_beg",1);         
                set("no_rideto", 1);
                set("no_flyto", 1);
                set("no_magic", 1); 
        set("no_sleep_room", 1); 
        set("max_carry_user" ,3);
        set("max_carry_exit" ,"out");
        
        setup();
}



