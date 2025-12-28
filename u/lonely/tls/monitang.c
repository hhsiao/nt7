#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIY"牟尼堂"NOR);
        set("long",@LONG
這是天龍寺高僧們的靜修之處，全以松木所制，板門木柱，木料均不去
皮，天然質樸，和一路行來金碧輝煌的殿堂截然不同。室中蒲團上分坐著三
個白鬚白眉的老和尚。
LONG
        );
        set("exits", ([
		"out": __DIR__"lang2",
	]));
	set("objects",([
		__DIR__"npc/ben-guan" : 1,
		__DIR__"npc/ben-xiang" : 1,
		__DIR__"npc/ben-can" : 1,
        ]));
        setup();
}
