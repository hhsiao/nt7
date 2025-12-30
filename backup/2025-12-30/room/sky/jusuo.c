// File(/data/room/sky/jusuo.c) of sky's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "居所");
	set ("long", @LONG
這就是海南島主人滅下休息、讀書的地方。樓上就是主人的臥室，
西面則是書房。 
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
    
        set("room_owner", "滅下");
        set("room_name", "海南島");
        set("room_id", "sky");
        set("room_owner_id", "sky");
        set("room_position", "南海之濱");
}
