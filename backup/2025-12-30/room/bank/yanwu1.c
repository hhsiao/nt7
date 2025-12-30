// File(/data/room/bank/yanwu1.c) of bank's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "金風細雨樓演武廳");
	set ("long", @LONG
這是金風細雨樓的演武廳，有時有些江湖朋友來會，想一試身手，
就在這裡比武較量。 
LONG );

        set("exits", ([
                "west" : __DIR__"yishiting",
        ]));

        set("objects", ([
                "/clone/weapon/zhubang" : 1,
                "/clone/weapon/zhujian" : 1,
                "/clone/weapon/mudao"   : 1,
        ]));

        set("no_sleep_room", 1);
        setup();

        set("room_owner", "錢莊");
        set("room_name", "金風細雨樓");
        set("room_id", "gold");
        set("room_owner_id", "bank");
        set("room_position", "[1;33m名人堂[2;37;0m");
}
