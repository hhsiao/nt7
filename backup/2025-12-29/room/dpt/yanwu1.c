// File(/data/room/dpt/yanwu1.c) of dpt's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "遊戲基地演武廳");
	set ("long", @LONG
這是遊戲基地的演武廳，有時有些江湖朋友來會，想一試身手，
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

        set("room_owner", "多炮塔");
        set("room_name", "遊戲基地");
        set("room_id", "gamebase");
        set("room_owner_id", "dpt");
        set("room_position", "南海之濱");
}
