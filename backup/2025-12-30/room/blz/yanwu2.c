// File(/data/room/blz/yanwu2.c) of blz's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "逍遙洞演武廳");
	set ("long", @LONG
這是逍遙洞的演武廳，有時有些江湖朋友來會，想一試身手，就
在這裡比武較量。 
LONG );

        set("exits", ([
                "east" : __DIR__"yishiting",
        ]));

        set("objects", ([
                "/clone/weapon/zhubang" : 1,
                "/clone/weapon/zhujian" : 1,
                "/clone/weapon/mudao"   : 1,
        ]));

        set("no_sleep_room", 1);
        setup();

        set("room_owner", "暴雪");
        set("room_name", "逍遙洞");
        set("room_id", "blz");
        set("room_owner_id", "blz");
        set("room_position", "青磚路");
}
