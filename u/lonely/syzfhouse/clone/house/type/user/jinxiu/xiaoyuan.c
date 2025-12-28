// xiaoyuan.c

inherit "/inherit/room/house_door";

void create()
{
    set("short", "小院");
    set("long", @LONG
一個不大的院子，穿過院子就是一間小屋，屋門緊閉著。
LONG);

    set("exits",
    ([
        "out"    : __FILE__,
    ]));

    set("owner_name", "某人");
    set("owner", "OWNER");
    set("huyuan", __DIR__"huyuan");
    set("outdoors", "OUTDOORS");
    set("set_exits", "north");
    set("set_entry", "xiaoting");
    set("max_laodu", 2500);
    set("now_laodu", 2500);

    setup();
    restore();
}
