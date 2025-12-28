//普雲洞
//cool@SJ,990605

#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
	set("short",HIY"普雲洞"NOR);
	set("long",@LONG
原來這普雲閣乃是一個小山洞，一進洞，門就無聲無息的關閉了，眼前是
一個天然形成的石甬道，洞的頂上有一條狹長的石縫，光線來自那裡，這條道
周圍分佈著幾個山洞，隱隱有些光從洞中透出。
LONG
	);
         
	set("exits", ([
		"out" : __DIR__"lsy",
		"north" : __DIR__"shangyang",
		"northup" : __DIR__"shaoshang",
		"northwest" : __DIR__"guanchong",
		"northeast" : __DIR__"zhongchong",
		"southwest" : __DIR__"shaoze",
		"southeast" : __DIR__"shaochong",
	]));
	set("no_fight",1);
	setup();
}
