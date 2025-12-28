// File(/data/room/blz/jusuo.c) of blz's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "居所");
	set ("long", @LONG
這就是逍遙洞主人暴雪休息、讀書的地方。樓上就是主人的臥室，
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
    
        set("room_owner", "暴雪");
        set("room_name", "逍遙洞");
        set("room_id", "blz");
        set("room_owner_id", "blz");
        set("room_position", "青磚路");
}
