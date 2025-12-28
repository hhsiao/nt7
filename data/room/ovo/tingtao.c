// File(/data/room/ovo/tingtao.c) of ovo's room
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
    
        set("room_owner", "小球球");
        set("room_name", "東北偏北");
        set("room_id", "dan");
        set("room_owner_id", "ovo");
        set("room_position", "碎石小道");
}
