#include <room.h>
inherit ROOM;

void create()
{
        set("short", "天龍寺齋堂");
        set("long", @LONG
這是天龍寺的齋堂。整個房間飄蕩著香味，一些僕役在不停的忙
碌著，桌上有各式的素菜、素酒，邊上一角放著好多剛摘回來的青菜，
一個大水桶放在旁邊，裡面裝滿了清水。你不由得舔舔嘴巴，
好象聽到你的肚子“咕咕咕”的叫了起來。
LONG);
        set("no_fight",1);
         set("exits", ([
                "south"  : __DIR__"yz2",
                "north"  : __DIR__"gulou",
        ]));
        set("resource/water", 1);
set("objects",([
		__DIR__"obj/rice" : 1,
		__DIR__"obj/dawan" : 1,
		__DIR__"obj/qingcai" : 2,
	]));

	set("no_fight", 1);

        set("coor/x",-340);
  set("coor/y",-350);
   set("coor/z",30);
   setup();
}
