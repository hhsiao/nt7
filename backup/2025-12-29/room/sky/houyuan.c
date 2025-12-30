// File(/data/room/sky/houyuan.c) of sky's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "後院");
	set ("long", @LONG
這是海南島的後院，正中一個假山，傲然而立、非常雄偉。下有
一水池，環山而走，悠然不息。東面乃是練武之處，西面是廚房。 
LONG );

        set("exits", ([
                "south" : __DIR__"zhongting",
                "north" : __DIR__"huayuan",
                "east"  : __DIR__"lianwu",
                "west"  : __DIR__"chufang",
        ]));

        set("outdoors", "nanhai");
        set("no_sleep_room", 1);
        setup();

        set("room_owner", "滅下");
        set("room_name", "海南島");
        set("room_id", "sky");
        set("room_owner_id", "sky");
        set("room_position", "南海之濱");
}
