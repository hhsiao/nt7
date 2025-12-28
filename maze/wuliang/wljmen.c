// Room: wljmen.c
// By River 98/12
inherit ROOM;
#include <ansi.h>
#include <wanted.h>
void create()
{
        set("short",HIY"無量劍宗"NOR);
	set("long", @LONG
「無量劍」於五代後唐年間在南詔無量山創派，掌門人居住無量山劍湖宮。
自大宋仁過年間分為東、北、西三宗，每隔五年，三宗門下弟子便在劍湖宮中
比武鬥劍，獲勝者入住劍湖宮。
LONG
	);
	set("exits", ([ 
	    "southdown" : __DIR__"xiaolu5",
	    "enter" : __DIR__"wlj",
        ]));

        set("objects", ([
              __DIR__"npc/yu_guangbiao" : 1,
              __DIR__"npc/wu_guangsheng" : 1,
        ]));

        set("outdoors", "大理");

	setup();
}

int valid_leave(object me,string dir)
{ 
	if (dir == "enter" && is_wanted(me))
		return 0;
     if( dir == "enter"
      && (present("yu guangbiao", environment(me))))
         return notify_fail("鬱光標上前攔住你的去路：無量劍重地，任何人不得擅自入內。\n");
     if( dir == "enter"
      && (present("wu guangsheng", environment(me))))
         return notify_fail("吳光勝上前攔住你的去路：無量劍重地，任何人不得擅自入內。\n");
         return ::valid_leave(me, dir);
}