// Room: keting.c
// By River 98/12
#include <wanted.h>
inherit ROOM;
void create()
{
        set("short", "客廳");
        set("long", @LONG
萬劫谷的正房，這是一間大客廳，寬敞明亮，青石鋪的地，兩邊靠牆擺著
的刀槍架，十八般兵器樣樣俱全。正中一張八仙桌，上有清茶一盞。旁邊是谷
主坐的太師椅。
LONG
        );
        set("exits", ([
            "east" : __DIR__"xiangfang",
            "north" : __DIR__"guzhong",
        ]));

        set("objects", ([
              __DIR__"npc/zhong_wanchou" : 1,
        ]));

        setup();
}

int valid_leave(object me,string dir)
{ 
	if (dir == "east" && is_wanted(me))
		return 0;
     if( query("gender", me) == "男性"
      && dir == "east"
      && (present("zhong wanchou", environment(me))))
         return notify_fail("鍾萬仇上前攔住你的去路：你這小白臉要找我夫人作甚？\n");
         return ::valid_leave(me, dir);
}