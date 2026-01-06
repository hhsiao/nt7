// caidi1.c 盤龍居菜地

//**inherit PRIVATE_ROOM;
inherit ROOM;                                   /* EXAMPLE */

void create()
{
    set("short", "菜地");                      /* EXAMPLE */
//**    set("short", "ROOM_NAME菜地");
    set("long", @LONG
這片菜園子幾畦地裡種了一些時鮮蔬菜。另外有幾個木樁搭起的
菜架子，供一些爬藤的蔬菜生長，不過你舉目看去，老大的一片菜園
子，居然疏疏落落的沒有幾棵菜。
LONG );

    set("default_long", "這片菜園子幾畦地裡種了一些時鮮蔬菜。另外有幾個木樁搭起的"     /* EXAMPLE */
                        "菜架子，供一些爬藤的蔬菜生長，不過你舉目看去，老大的一片菜園" /* EXAMPLE */
                        "子，居然疏疏落落的沒有幾棵菜。");                          /* EXAMPLE */
                                                                                 /* EXAMPLE */
    set("exits", ([
        "east" : __DIR__"dayuan",
    ]));
    set("outdoors", "OUTDOORS");
    set("no_sleep_room", 1);
    setup();

//**    set("room_owner", "ROOM_OWNER");
//**    set("room_name", "ROOM_NAME");
//**    set("room_id", "ROOM_ID");
//**    set("room_owner_id", "ROOM_OWNER_ID");
//**    set("room_position", "ROOM_POSITION");
}
