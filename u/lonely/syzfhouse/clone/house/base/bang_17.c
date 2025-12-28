
inherit "/inherit/room/house_base";

void create()
{
    set("short", "太平鎮北");
    set("long", @LONG
此處位於太平鎮北郊之外，平日車馬稀少、人跡罕至。稀疏的樹
林間掩映著好大的一片宅院，似乎是某個幫會的駐地所在。
LONG);

    set("exits",
    ([
        "south"  : "/d/wudang/caishi",
    ]));

    set("outdoors", "wudang");
    set("max_build", 1);
    set("can_build", "bang");

    setup();
    restore();
}
