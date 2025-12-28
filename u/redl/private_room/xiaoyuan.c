// File(/data/room/redl/xiaoyuan.c) of redl's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "蓮池小院");
	set ("long", @LONG
這裡是一個四四方方的院子，院牆都是用紅磚砌成，不算高，但
是非常清爽利落。院中幾棵古木成蔭，隱然有一種世外桃源的感覺。
院子外面隱約是溪岸小路，院子的北面有一扇木門。 
LONG );

        set("room_key", "1 of redl");
        setup();

        set("exits", ([
                "out"    : "/d/chengdu/path1",
        ]));

        set("outdoors", "chengdu");
        set("no_sleep_room", 1);
        set("valid_startroom", 1);

        set("KEY_DOOR", ([
                "exit" : "north",
                "room" : __DIR__"dating",
        ]));
    
        set("room_owner", "紅蓮老祖");
        set("room_name", "蓮池");
        set("room_id", "redl");
        set("room_owner_id", "redl");
        set("room_position", "溪岸小路");
}
