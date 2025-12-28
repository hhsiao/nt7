#include <room.h>
inherit ROOM;

void create()
{
	set("short", "天龍寺齋堂");
        set("long", @LONG
這是天龍寺的齋堂。整個房間飄蕩著香味，一些僕役在不停的忙
著，邊上一角放著好多剛摘回來的青菜，你不由得舔舔嘴巴，好象聽
到你的肚子“咕咕咕”的叫了起來。
LONG);
        set("exits", ([
		"east"  : __DIR__"dmg",
	]));
        setup();
}

