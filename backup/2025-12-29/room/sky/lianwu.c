// File(/data/room/sky/lianwu.c) of sky's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "練武場");
	set ("long", @LONG
此處便是海南島的練武場，人在江湖，武功萬萬不可荒廢。 
LONG );

        set("exits", ([
                "west" : __DIR__"houyuan",
        ]));

        set("objects", ([
                "/clone/npc/mu-ren" : 4,
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
