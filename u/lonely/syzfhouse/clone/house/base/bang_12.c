
inherit "/inherit/room/house_base";

void create()
{
    set("short", "北市口外");
    set("long", @LONG
北市口外行人十分稀少，南面經北市口東行，可通往地安門西大
街，同樣也是人跡罕至。一片氣派不凡的宅院座落於此，看上去似乎
是某個幫會的駐地所在。
LONG);

    set("exits",
    ([
        "south" : "/d/beijing/beishi-kou",
    ]));

    set("outdoors", "beijing");
    set("max_build", 1);
    set("can_build", "bang");

    setup();
    restore();
}
