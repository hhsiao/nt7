#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
    set("short", "國子監");
    set("long", @LONG
這裡就是京城的國子監。國子監是朝廷培養人才的地方。高高低
低的桌子排了兩排。在這裡不時可以看到三三兩兩的學生模樣的人大
聲爭辯著什麼問題，還有一些老先生們蹙著眉頭匆匆的走過，象是在
思考著什麼問題。[2；37；0m
LONG );
    set("exits", ([
        "south" : "/d/beijing/dong_2",
    ]));
    set("objects", ([
        "/d/beijing/npc/shusheng1" : 3,
    ]));
    set("outdoors", "beijing");
	set("coor/x", -2790);
	set("coor/y", 7740);
	set("coor/z", 0);
	setup();
    replace_program(ROOM);
}
