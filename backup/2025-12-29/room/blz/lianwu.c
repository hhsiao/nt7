// File(/data/room/blz/lianwu.c) of blz's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "練武場");
	set ("long", @LONG
此處便是逍遙洞的練武場，人在江湖，武功萬萬不可荒廢。 
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
    
        set("room_owner", "暴雪");
        set("room_name", "逍遙洞");
        set("room_id", "blz");
        set("room_owner_id", "blz");
        set("room_position", "青磚路");
}
