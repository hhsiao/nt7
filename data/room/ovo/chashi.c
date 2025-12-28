// File(/data/room/ovo/chashi.c) of ovo's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "茶室");
	set ("long", @LONG
是一個玲瓏小巧的茶室，很是顯得精緻。正中有一茶几，兩旁立
著兩個妙齡少女，正在聽候主人的吩咐(tea)。 
LONG );

        set("exits", ([
                "west"  : __DIR__"yingke",
        ]));

        set("objects", ([
                "/d/room/roomnpc/teagirl" : 2,
        ]));

        create_door("west", "木門", "east", DOOR_CLOSED);

        set("no_sleep_room", 1);
        setup();

        set("room_owner", "小球球");
        set("room_name", "東北偏北");
        set("room_id", "dan");
        set("room_owner_id", "ovo");
        set("room_position", "碎石小道");
}
