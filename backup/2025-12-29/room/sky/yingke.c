// File(/data/room/sky/yingke.c) of sky's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "海南島迎客廳");
	set ("long", @LONG
這裡是海南島的主人滅下迎接八方來客的地方。大凡客人來拜見
滅下，少不得在這裡寒暄敘話，了盡仰慕之情。東面通往一個茶室，
是主人陪同客人品嚐天下名茶之處。 
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

        set("room_owner", "滅下");
        set("room_name", "海南島");
        set("room_id", "sky");
        set("room_owner_id", "sky");
        set("room_position", "南海之濱");
}
