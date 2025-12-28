
inherit "/inherit/room/house_base";

void create()
{
    set("short", "華山村東");
    set("long", @LONG
沿著華山村內的碎石路一直向東，走出這個小小村落不多遠，卻
發現有好大一片宅院座落於此，看上去似乎是某個幫會的駐地所在。
LONG);

    set("exits",
    ([
        "northwest" : "/d/village/eexit",
    ]));

    set("outdoors", "village");
    set("max_build", 1);
    set("can_build", "bang");

    setup();
    restore();
}
