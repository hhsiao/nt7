// ken 1999.12.9

#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
	set("short", "後花園");
	set("long", @LONG
你獨自在花徑徘徊，不覺來到了園子的深幽之處，只見林木蔥鬱，
奇花爛漫，一帶清流，從花木深處瀉於石隙之下，剛才的一盡奢華
皆隱於山坳樹梢之間，景色美極了，也清幽極了。
LONG	);
	set("exits", ([ 
  "east" : __DIR__"fenglin",
  "west" : __DIR__"poor",
  "southup" : __DIR__"yyl",
]));
	set("coor/x",-30);
	set("coor/y",1150);
	set("coor/z",40);
	setup();
}
