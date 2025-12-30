// File(/data/room/alxpang/zuoxiang.c) of alxpang's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "左廂房");
	set ("long", @LONG
這是海景房的左廂房，是客人居住的地方。雖然不算奢華，卻也
佈置得非常舒適。一張床整齊乾淨，沒有多少折紋，而窗簾厚大結實，
使屋內光線恰到好處。 
LONG );

        set("exits", ([
                "west" : __DIR__"zhongting",
        ]));

        set("sleep_room", 1);
        set("no_fight", 1);

        create_door("west", "木門", "east", DOOR_CLOSED);

        set("room_owner", "風四郎");
        set("room_name", "海景房");
        set("room_id", "sea");
        set("room_owner_id", "alxpang");
        set("room_position", "青磚路");
}
