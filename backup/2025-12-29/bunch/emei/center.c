// Create by BUNCH_D written by Lonely
// center.c

#include <ansi.h>
#include <room.h>
inherit ROOM;
#define PLACE   "hz"
#define TYPE    "good"

// int is_bunch_room() { return 1; }
int sort_by_id(mapping quest1, mapping quest2);

void create()
{
	set("short", "峨眉洗象總壇");
	set("long", "房間的牆上有一塊牌子(paizi)。加入幫派峨眉洗象的玩家，可以在這裡選擇任務去完成。\n");
	set("objects", ([
		__DIR__"npc/quester" : 1,
	]));
	set("exits", ([
		"south" : __DIR__"room9", 
	]));

	setup();
}

#include <bang_good.h>
