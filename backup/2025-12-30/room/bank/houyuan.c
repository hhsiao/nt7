// File(/data/room/bank/houyuan.c) of bank's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "後院");
	set ("long", @LONG
這是金風細雨樓的後院，正中一個假山，傲然而立、非常雄偉。
下有一水池，環山而走，悠然不息。東面乃是練武之處，西面是廚房。
LONG );

        set("exits", ([
                "south" : __DIR__"zhongting",
                "north" : __DIR__"huayuan",
                "east"  : __DIR__"lianwu",
                "west"  : __DIR__"chufang",
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
