// Room: hslin.c
// By River 98/12
inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", "黑森林");
	set("long", @LONG
你快步而行，只見迎面黑壓壓的一座大森林。走近前去，只見左首一排九
株大松樹參天並列，好象有些異樣。
LONG
	);
	set("exits", ([
		"south" : __DIR__"tiesuo",
	]));
	set("outdoors", "大理");
	setup();
}

void init()
{
	add_action("do_enter","enter");
}

int do_enter(string arg)
{
	object me = this_player();

	if ( arg!="第四株" ) return notify_fail ("你要往哪裡走？\n");
	if ( me->is_busy() || me->is_fighting() ) return notify_fail ("你現在正忙著呢。\n");

	write(HIW"\n你繞到第四株樹後，撥開長草，樹上出現一洞，你鑽進樹洞，左手撥開枯草，\n"+
              "右手摸到一個大鐵環，用力提起，木板掀開，下面便是一道石級。走下幾級，\n"+
              "雙手託著木板放回原處，沿石級向下走去，三十餘級後石級右轉，數丈後折而\n"+
              "向上，上行三十餘級，來到平地。\n\n"NOR,me);
	me->move(__DIR__"caodi");
	return 1;
}