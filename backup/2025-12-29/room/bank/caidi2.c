// File(/data/room/bank/caidi2.c) of bank's room
// Create by LUBAN written by Doing Lu

     inherit PRIVATE_ROOM;

void create()
{
        set("short", "金風細雨樓菜地");
	set ("long", @LONG
這片菜園子幾畦地裡種了一些時鮮蔬菜。另外有幾個木樁搭起的
菜架子，供一些爬藤的蔬菜生長，不過你舉目看去，老大的一片菜園
子，居然疏疏落落的沒有幾棵菜。 
LONG );

        set("exits", ([
                "west" : __DIR__"dayuan",
        ]));
        set("outdoors", "unknow");
        set("no_sleep_room", 1);
        setup();

        set("room_owner", "錢莊");
        set("room_name", "金風細雨樓");
        set("room_id", "gold");
        set("room_owner_id", "bank");
        set("room_position", "[1;33m名人堂[2;37;0m");
}
