// ken 1999.12.9

#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
	set("short", "廚房");
	set("long", @LONG
這裡自從山莊建立時起，就一直沒有閒來過，由於來訪的賓客很
多，所有的人都一生不吭的忙碌著。灶上放著一籠剛蒸好的珍珠
蟹黃包和一碗熱氣騰騰的茯苓燕窩湯。
LONG	);
	set("exits", ([ 
  "eastup" : __DIR__"fgaden",
]));
        set("objects",([
			__DIR__"npc/cook" : 1,
       	]) );
	set("coor/x",-40);
	set("coor/y",1090);
	set("coor/z",30);
	setup();
}
