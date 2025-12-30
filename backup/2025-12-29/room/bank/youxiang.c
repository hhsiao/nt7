// File(/data/room/bank/youxiang.c) of bank's room
// Create by LUBAN written by Doing Lu

#include <room.h>

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "右廂房");
	set ("long", @LONG
這是金風細雨樓的右廂房，是客人居住的地方。雖然不算奢華，
卻也佈置得非常舒適。一張床整齊乾淨，沒有多少折紋，而窗簾厚大
結實，使屋內光線恰到好處。 
LONG );

        set("exits", ([
                "east" : __DIR__"zhongting",
        ]));

        set("sleep_room", 1);
        set("no_fight", 1);

        create_door("east", "木門", "west", DOOR_CLOSED);

        setup();

        set("room_owner", "錢莊");
        set("room_name", "金風細雨樓");
        set("room_id", "gold");
        set("room_owner_id", "bank");
        set("room_position", "[1;33m名人堂[2;37;0m");
}
