// File(/data/room/bank/yingke.c) of bank's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "金風細雨樓迎客廳");
	set ("long", @LONG
這裡是金風細雨樓的主人錢莊迎接八方來客的地方。大凡客人來
拜見錢莊，少不得在這裡寒暄敘話，了盡仰慕之情。東面通往一個茶
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

        set("room_owner", "錢莊");
        set("room_name", "金風細雨樓");
        set("room_id", "gold");
        set("room_owner_id", "bank");
        set("room_position", "[1;33m名人堂[2;37;0m");
}
