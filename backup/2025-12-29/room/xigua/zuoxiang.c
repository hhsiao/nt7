// File(/data/room/xigua/zuoxiang.c) of xigua's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "左廂房");
	set ("long", @LONG
這是水果攤的左廂房，是客人居住的地方。雖然不算奢華，卻也
佈置得非常舒適。一張床整齊乾淨，沒有多少折紋，而窗簾厚大結實，
使屋內光線恰到好處。 
LONG );

        set("exits", ([
                "west" : __DIR__"zhongting",
        ]));

        set("sleep_room", 1);
        set("no_fight", 1);

        create_door("west", "木門", "east", DOOR_CLOSED);

        set("room_owner", "西瓜");
        set("room_name", "水果攤");
        set("room_id", "sgt");
        set("room_owner_id", "xigua");
        set("room_position", "碎石小道");
}
