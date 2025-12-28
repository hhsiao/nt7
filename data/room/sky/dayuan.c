// File(/data/room/sky/dayuan.c) of sky's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "海南島大院");
	set ("long", @LONG
這是一個寬闊的院落，種著各種樹木，陽光照下來透過樹蔭投下
層層影子。一條大路通向裡面，踩得非常平滑的，看來是經常有人來
往。 
LONG );

        set("exits", ([
                "north"  : __DIR__"qianting",
                "east"   : __DIR__"caidi2",
                "west"   : __DIR__"caidi1",
                "out"    : "/d/xiakedao/haibin",
        ]));

        set("outdoors", "nanhai");
        set("no_sleep_room", 1);
        set("valid_startroom", 1);
        setup();

        set("room_owner", "滅下");
        set("room_name", "海南島");
        set("room_id", "sky");
        set("room_owner_id", "sky");
        set("room_position", "南海之濱");
}
