
inherit "/inherit/room/house_base";

void create()
{
    set("short", "燕山村西");
    set("long", @LONG
沿著燕山村裡的小土路一直西行，來到打穀場邊的村頭，卻發現
有好大一片宅院座落於此，看上去似乎是某個幫會的駐地所在。
LONG);

    set("exits",
    ([
        "east" : "/d/shanhai-guan/chundao3",
    ]));

    set("outdoors", "shanhai-guan");
    set("max_build", 1);
    set("can_build", "bang");

    setup();
    restore();
}
