#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
        set("short", HIW"小洞天"NOR);
        set("long", @LONG
你無意間闖入了一個山谷，這裡幽靜異常，你不由的心裡有些發毛。
山谷兩側都是峭壁，南面一直通向山谷深處，這裡沒有什麼路，灌木
樹枝擋住了前進的路。西面是你進來的路
LONG);
        set("outdoors", "天龍寺");
        set("exits", ([             
               "west" : __DIR__"songlin-2",
                      ]));
set("objects",([
//        "/d/dali/npc/yetu" : 1,
		]));

        setup();
}

