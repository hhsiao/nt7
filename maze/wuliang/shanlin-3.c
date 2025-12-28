// Modify By River 98/12
inherit ROOM;

void create()
{
	set("short", "森林");
	set("long", @LONG
行出數里，進了一座大樹林中，四周都是是參天古木，當日陽光燦爛，林
中卻黑沉沉地宛如黃昏。北面一直通向林子深處。?
LONG
	);
        set("outdoors", "大理");

	set("exits", ([
             "north" : __DIR__"shanlin-4",
	     "westdown" : __DIR__"shanlin-2",
	]));
        set("objects", ([
	      __DIR__"obj/yeguo" : 2,
	]));
	setup();
}