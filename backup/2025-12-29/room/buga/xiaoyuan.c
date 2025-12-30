// File(/data/room/buga/xiaoyuan.c) of buga's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "蟲洞小院");
	set ("long", @LONG
這裡是一個四四方方的院子，院牆都是用紅磚砌成，不算高，但
是非常清爽利落。院中幾棵古木成蔭，隱然有一種世外桃源的感覺。
院子外面隱約是碎石小道，院子的北面有一扇木門。 
LONG );

        set("room_key", "1 of buga");
        setup();

        set("exits", ([
                "out"    : "/d/room/playtown/road16",
        ]));

        set("outdoors", "playertown");
        set("no_sleep_room", 1);
        set("valid_startroom", 1);

        set("KEY_DOOR", ([
                "exit" : "north",
                "room" : __DIR__"dating",
        ]));
    
        set("room_owner", "紅臭蟲");
        set("room_name", "蟲洞");
        set("room_id", "bugaa");
        set("room_owner_id", "buga");
        set("room_position", "碎石小道");
}
