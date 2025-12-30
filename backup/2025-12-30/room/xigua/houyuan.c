// File(/data/room/xigua/houyuan.c) of xigua's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "後院");
	set ("long", @LONG
這是水果攤的後院，正中一個假山，傲然而立、非常雄偉。下有
一水池，環山而走，悠然不息。東面乃是練武之處，西面是廚房。 
LONG );

        set("exits", ([
                "south" : __DIR__"zhongting",
                "north" : __DIR__"huayuan",
                "east"  : __DIR__"lianwu",
                "west"  : __DIR__"chufang",
        ]));

        set("outdoors", "playertown");
        set("no_sleep_room", 1);
        setup();

        set("room_owner", "西瓜");
        set("room_name", "水果攤");
        set("room_id", "sgt");
        set("room_owner_id", "xigua");
        set("room_position", "碎石小道");
}
