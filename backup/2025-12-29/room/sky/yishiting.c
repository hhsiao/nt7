// File(/data/room/sky/yishiting.c) of sky's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "議事廳");
	set ("long", @LONG
這就是海南島主人滅下和重要人物商量江湖大事之處，正中有不
少桌椅，側面是屏風，廳堂中掛著兩個條幅，兩旁通往演武廳。 
LONG );

        set("exits", ([
                "east"   : __DIR__"yanwu1",
                "west"   : __DIR__"yanwu2",
                "north"  : __DIR__"zhongting",
                "south"  : __DIR__"yingke",
        ]));

        set("no_sleep_room", 1);
        setup();

        set("room_owner", "滅下");
        set("room_name", "海南島");
        set("room_id", "sky");
        set("room_owner_id", "sky");
        set("room_position", "南海之濱");
}
