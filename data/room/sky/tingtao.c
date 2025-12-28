// File(/data/room/sky/tingtao.c) of sky's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "聽濤閣");
	set ("long", @LONG
這是竹林一角的聽濤閣，在這裡風吹竹葉的陣陣濤聲聽的非常真
切，真是讓人心曠神怡。實在是一個參悟武功的好去處。 
LONG );

        set("exits", ([
                "west" : __DIR__"zhulin",
        ]));

        set("sleep_room", 1);
        setup();

        set("research_improve", 15);  //15% improved
    
        set("room_owner", "滅下");
        set("room_name", "海南島");
        set("room_id", "sky");
        set("room_owner_id", "sky");
        set("room_position", "南海之濱");
}
