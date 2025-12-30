// File(/data/room/xigua/lianwu.c) of xigua's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "練武場");
	set ("long", @LONG
此處便是水果攤的練武場，人在江湖，武功萬萬不可荒廢。 
LONG );

        set("exits", ([
                "west" : __DIR__"houyuan",
        ]));

        set("objects", ([
                "/clone/npc/mu-ren" : 4,
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
