// File(/data/room/alxpang/jusuo.c) of alxpang's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "居所");
	set ("long", @LONG
這就是海景房主人風四郎休息、讀書的地方。樓上就是主人的臥
室，西面則是書房。 
LONG );

        set("exits", ([
                "up"   : __DIR__"woshi",
                "west" : __DIR__"shufang",
        ]));

        set("no_sleep_room", 1);
        setup();

        set("KEY_DOOR", ([
                "exit" : "east",
                "room" : __DIR__"huayuan",
        ]));
    
        set("room_owner", "風四郎");
        set("room_name", "海景房");
        set("room_id", "sea");
        set("room_owner_id", "alxpang");
        set("room_position", "青磚路");
}
