// Create by lonely@NT
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "石壁"NOR);
        set("long", @LONG
這裡快到「大宋」軍營駐紮地了，遠遠地可以看見大營內飛揚的塵土，不
時有幾匹快馬飛奔進出，你正欲再看，忽然嗖地一枚冷箭從你頭上飛過，還是
趕快離開的好。
LONG
);

        set("no_fly", "1");
        set("exits", ([ /* sizeof() == 5 */   
               "south" :   __DIR__"shance",
               "north" :   __DIR__"luanshi8",
        ]));    

        set("objects", ([

        ]));
    
        setup();
}

int valid_leave(object me, string dir)
{
          if (!userp(me))         return ::valid_leave(me, dir);
        if ( dir == "north" )
        return notify_fail("帶頭大哥一下擋在你面前，"+HIW"白眼"NOR+"一翻：在這裡待著，不要輕舉亂動！\n");
        return 1;
}

