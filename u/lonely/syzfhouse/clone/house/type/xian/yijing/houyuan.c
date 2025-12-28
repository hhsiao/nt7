// houyuan.c

inherit "/inherit/room/house_room";

void create()
{
    set("short", "後院");
    set("long", @LONG
這是宅子的後院，正中一座假山，傲然而立，氣勢不凡。下有
流水淙淙，環山而走，悠然不息。
LONG);

    set("exits",
    ([
        "south" : __DIR__"houting",
    ]));

    set("outdoors", "OUTDOORS");
    set("owner", "OWNER");
    set("owner_name", "某人");
    set("resource/water", "泉水");

    setup();
    restore();
}
