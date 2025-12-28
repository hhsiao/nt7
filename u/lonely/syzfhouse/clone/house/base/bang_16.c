
inherit "/inherit/room/house_base";

void create()
{
    set("short", "終南山腳");
    set("long", @LONG
這裡已是終南山脈地界，一條山道蜿蜒通向山頂的雲霧中，從中
彷彿能看見巍峨聳立的重陽宮。一片宅院掩映在道旁的樹林間，看上
去似乎是某個幫會的駐地所在。
LONG);

    set("exits",
    ([
        "northwest" : "/d/quanzhen/shanjiao1",
    ]));

    set("outdoors", "quanzhen");
    set("max_build", 1);
    set("can_build", "bang");

    setup();
    restore();
}
