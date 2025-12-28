
inherit "/inherit/room/house_base";

void create()
{
    set("short", "清平路西");
    set("long", @LONG
清平路向南，直出福州南門。路面十分地乾淨，聽著街上行人的
閩南話，雖然一個字也聽不懂，但總是覺得怪好聽的。路的西面座落
著好大的一片宅院，看上去似乎是某個幫會的駐地所在。
LONG);

    set("exits",
    ([
        "east"  : "/d/fuzhou/qingping-lu",
    ]));

    set("outdoors", "fuzhou");
    set("max_build", 1);
    set("can_build", "bang");

    setup();
    restore();
}
