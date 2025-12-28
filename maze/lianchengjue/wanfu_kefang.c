
#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", HIG + "萬府客房" + NOR);
        set("long", "這裡是荊州萬府，乃萬震山府邸，四處朱牆高瓦，好不氣派。\n"); 
        
        set("no_bid", 1);
        set("no_magic", 1);
        set("no_rideto", 1);
        
        set("exits", ([ 
                "out" : "/d/city/wumiao", 
        ]));

        setup();
}

