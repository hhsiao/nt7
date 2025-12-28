#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", MAG"雨花院"NOR);
        set("long",@LONG
此處依山傍水，一條小溪從你眼前靜靜流過，一座精雕木橋橫跨
其上，與其倒影恰成一圓，映著空靈的水面。溪旁遍植百花，風吹花
落，便有了雨花院之稱。院內雨花閣精舍乃是寺中藏經存書之處，雖
有幾個和尚來來去去，卻不聞一絲聲響。
LONG);
        set("outdoors","天龍寺");
        set("exits", ([
                "south" : __DIR__"wwj",
		"enter" : __DIR__"yuhua1",
                "east" : __DIR__"songlin2",
	]));
        set("coor/x",-310);
  set("coor/y",-290);
   set("coor/z",40);
   setup();
}
