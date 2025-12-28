// File(/data/room/ovo/dayuan.c) of ovo's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "東北偏北大院");
	set ("long", @LONG
這是一個寬闊的院落，種著各種樹木，陽光照下來透過樹蔭投下
層層影子。一條大路通向裡面，踩得非常平滑的，看來是經常有人來
往。 
LONG );

        set("exits", ([
                "north"  : __DIR__"qianting",
                "east"   : __DIR__"caidi2",
                "west"   : __DIR__"caidi1",
                "out"    : "/d/room/playtown/road5",
        ]));

        set("outdoors", "playertown");
        set("no_sleep_room", 1);
        set("valid_startroom", 1);
        setup();

        set("room_owner", "小球球");
        set("room_name", "東北偏北");
        set("room_id", "dan");
        set("room_owner_id", "ovo");
        set("room_position", "碎石小道");
}
