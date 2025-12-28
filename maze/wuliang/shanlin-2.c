// Modify By River 98/12
inherit ROOM;

void create()
{
	set("short", "山坡");
	set("long", @LONG
這裡是一個荒涼幽僻的山谷了，你沿著山坡的斜面向東面攀去，那面是一
片黑壓壓的森林了，你眼見段延慶一下子就逃進了黑林中。
LONG
	);
        set("outdoors", "大理");
	set("exits", ([
            "eastup" : __DIR__"shanlin-3",
	    "west" : __DIR__"shanlin-1",
	]));

	setup();
}