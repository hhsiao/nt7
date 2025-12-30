// File(/data/room/xigua/yingke.c) of xigua's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "水果攤迎客廳");
	set ("long", @LONG
這裡是水果攤的主人西瓜迎接八方來客的地方。大凡客人來拜見
西瓜，少不得在這裡寒暄敘話，了盡仰慕之情。東面通往一個茶室，
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

        set("room_owner", "西瓜");
        set("room_name", "水果攤");
        set("room_id", "sgt");
        set("room_owner_id", "xigua");
        set("room_position", "碎石小道");
}
