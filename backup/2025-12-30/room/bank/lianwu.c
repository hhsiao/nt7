// File(/data/room/bank/lianwu.c) of bank's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "練武場");
	set ("long", @LONG
此處便是金風細雨樓的練武場，人在江湖，武功萬萬不可荒廢。
LONG );

        set("exits", ([
                "west" : __DIR__"houyuan",
        ]));

        set("objects", ([
                "/clone/npc/mu-ren" : 4,
        ]));

        set("outdoors", "unknow");
        set("no_sleep_room", 1);

        setup();
    
        set("room_owner", "錢莊");
        set("room_name", "金風細雨樓");
        set("room_id", "gold");
        set("room_owner_id", "bank");
        set("room_position", "[1;33m名人堂[2;37;0m");
}
