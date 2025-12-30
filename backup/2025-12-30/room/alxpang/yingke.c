// File(/data/room/alxpang/yingke.c) of alxpang's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "海景房迎客廳");
	set ("long", @LONG
這裡是海景房的主人風四郎迎接八方來客的地方。大凡客人來拜
見風四郎，少不得在這裡寒暄敘話，了盡仰慕之情。東面通往一個茶
室，是主人陪同客人品嚐天下名茶之處。 
LONG );

        set("exits", ([
                "north"  : __DIR__"yishiting",
                "south"  : __DIR__"zoudao",
                "east"   : __DIR__"chashi",
        ]));

        create_door("east", "木門", "west", DOOR_CLOSED);

        set("objects", ([
                "/d/room/roomnpc/yahuan" : 2,
        ]));

        set("no_sleep_room", 1);
        setup();

        set("room_owner", "風四郎");
        set("room_name", "海景房");
        set("room_id", "sea");
        set("room_owner_id", "alxpang");
        set("room_position", "青磚路");
}
