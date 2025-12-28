
#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", HIG + "萬府廂房" + NOR);
        set("long", "這裡是萬府西面的廂房，床上睡著一個女子，周圍站滿了萬府的弟子和家丁。\n"); 
        
        set("no_bid", 1);
        set("no_magic", 1);
        set("no_rideto", 1);
        
        set("objects", ([
                __DIR__"npc/qifang" : 1,
        ]));

        set("exits", ([ 
                "out" : "/d/city/wumiao", 
        ]));

        setup();
}

