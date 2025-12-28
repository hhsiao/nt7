// File(/data/room/buga/dating.c) of buga's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "蟲洞大廳");
	set ("long", @LONG
這就是蟲洞主人紅臭蟲迎送客人的地方。正中有些桌椅，側面是
兩扇屏風。東首是主人紅臭蟲的房間，有一扇木門虛掩著。南邊是大
門，出去就是院子。 
LONG );

        setup();

        set("exits", ([
                "east"   : __DIR__"woshi",
                "north"  : __DIR__"houyuan",
        ]));

        create_door("east", "木門", "west", DOOR_CLOSED);

        set("no_sleep_room", 1);

        set("KEY_DOOR", ([
                "exit" : "south",
                "room" : __DIR__"xiaoyuan",
        ]));
    
        set("room_owner", "紅臭蟲");
        set("room_name", "蟲洞");
        set("room_id", "bugaa");
        set("room_owner_id", "buga");
        set("room_position", "碎石小道");
}
