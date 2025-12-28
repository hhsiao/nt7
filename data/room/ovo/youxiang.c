// File(/data/room/ovo/youxiang.c) of ovo's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "右廂房");
	set ("long", @LONG
這是東北偏北的右廂房，是客人居住的地方。雖然不算奢華，卻
也佈置得非常舒適。一張床整齊乾淨，沒有多少折紋，而窗簾厚大結
實，使屋內光線恰到好處。 
LONG );

        set("exits", ([
                "east" : __DIR__"zhongting",
        ]));

        set("sleep_room", 1);
        set("no_fight", 1);

        create_door("east", "木門", "west", DOOR_CLOSED);

        setup();

        set("room_owner", "小球球");
        set("room_name", "東北偏北");
        set("room_id", "dan");
        set("room_owner_id", "ovo");
        set("room_position", "碎石小道");
}
