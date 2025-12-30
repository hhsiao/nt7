// File(/data/room/alxpang/dayuan.c) of alxpang's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "海景房大院");
	set ("long", @LONG
這是一個寬闊的院落，種著各種樹木，陽光照下來透過樹蔭投下
層層影子。一條大路通向裡面，踩得非常平滑的，看來是經常有人來
往。 
LONG );

        set("exits", ([
                "north"  : __DIR__"qianting",
                "east"   : __DIR__"caidi2",
                "west"   : __DIR__"caidi1",
                "out"    : "/d/room/playtown/road14",
        ]));

        set("outdoors", "playertown");
        set("no_sleep_room", 1);
        set("valid_startroom", 1);
        setup();

        set("room_owner", "風四郎");
        set("room_name", "海景房");
        set("room_id", "sea");
        set("room_owner_id", "alxpang");
        set("room_position", "青磚路");
}
