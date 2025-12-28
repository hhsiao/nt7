// File(/data/room/wwcha/xiaoyuan.c) of wwcha's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "我的小院");
	set ("long", @LONG
這裡是一個不大的院子，角落裡栽了幾棵樹，地上零零散散有一
些碎落葉片。院門虛掩，穿過院子就是一個小屋，非常精緻。 
LONG );

        set("room_key", "1 of wwcha");
        setup();

        set("exits", ([
                "out"    : "/d/huashan/shanhongpb",
        ]));

        set("outdoors", "huashan");
        set("no_sleep_room", 1);
        set("valid_startroom", 1);

        set("KEY_DOOR", ([
                "exit" : "north",
                "room" : __DIR__"dulewu",
        ]));
    
        set("room_owner", "大波龍");
        set("room_name", "我的");
        set("room_id", "popo");
        set("room_owner_id", "wwcha");
        set("room_position", "山洪瀑布");
}
