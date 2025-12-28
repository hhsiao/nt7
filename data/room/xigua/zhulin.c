// File(/data/room/xigua/zhulin.c) of xigua's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "竹林");
	set ("long", @LONG
這裡種著好大一片竹林，非常幽靜。風一起就聽竹葉沙沙的響，
有時西瓜就去聽濤閣默聽竹浪濤聲，參悟武功。 
LONG );

        set("exits", ([
                "west" : __DIR__"huayuan",
                "east" : __DIR__"tingtao",
        ]));

        set("outdoors", "playertown");
        set("sleep_room", 1);
        setup();

        set("room_owner", "西瓜");
        set("room_name", "水果攤");
        set("room_id", "sgt");
        set("room_owner_id", "xigua");
        set("room_position", "碎石小道");
}
