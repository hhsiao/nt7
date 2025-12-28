// Create by BUNCH_D written by Lonely
// entry.c

#include <ansi.h>
#include <room.h>
inherit ROOM;

int is_bunch_room() { return 1; }

void create()
{
        set("short", "空房間 - 請使用 cshort 來編輯標題");
        set("long", "這是一間什麼也沒有的空房間，請利用 clong 來編輯房間敘述。\n");

        set("exits", ([
                "north" : __DIR__"room0",
		"out" : "/d/hangzhou/xizhaoshan", 
	]));

	setup();
}

