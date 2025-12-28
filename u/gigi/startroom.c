// This program is a part of NITAN MudLIB

#include <ansi.h>
#include <room.h>
inherit ROOM; 


void create()
{
        set("short", "起點"); 
        set("long", HIG "這是一個待建的房間。\n" NOR);

        set("exits", ([ /* sizeof() == 1 */
                "east" : "/data/room/redl/dadian",
        ]));

        set("no_rideto", 1);
        set("no_flyto", 1);
        setup();
}



