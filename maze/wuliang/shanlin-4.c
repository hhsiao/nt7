// Modify By River 98/12
inherit ROOM;

void create()
{
	set("short", "森林");
	set("long", @LONG
這裡四周都是是參天古木，當日陽光燦爛，林中卻黑沉沉地宛如黃昏，越
走樹林越密，有時不得不側身而行。?
LONG
	);
        set("outdoors", "大理");

	set("exits", ([
            "south" : __DIR__"shanlin-3",
	    "west" : __DIR__"shanlin-5",
	]));

	setup();
}