// File(/data/room/dpt/zhulin.c) of dpt's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "竹林");
	set ("long", @LONG
這裡種著好大一片竹林，非常幽靜。風一起就聽竹葉沙沙的響，
有時多炮塔就去聽濤閣默聽竹浪濤聲，參悟武功。 
LONG );

        set("exits", ([
                "west" : __DIR__"huayuan",
                "east" : __DIR__"tingtao",
        ]));

        set("outdoors", "nanhai");
        set("sleep_room", 1);
        setup();

        set("room_owner", "多炮塔");
        set("room_name", "遊戲基地");
        set("room_id", "gamebase");
        set("room_owner_id", "dpt");
        set("room_position", "南海之濱");
}
