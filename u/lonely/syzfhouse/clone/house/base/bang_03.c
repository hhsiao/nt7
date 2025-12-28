
inherit "/inherit/room/house_base";

void create()
{
    set("short", "清名橋畔");
    set("long", @LONG
下得清名橋向東走，沿著護城河畔一條青黃色花崗石鋪就的小路
曲折前行，遠處隱約可見有好大的一片宅院，看上去似乎是某個幫會
的駐地所在。
LONG);

    set("exits",
    ([
        "west"  : "/d/wuxi/qiao3",
    ]));

    set("outdoors", "wuxi");
    set("max_build", 1);
    set("can_build", "bang");

    setup();
    restore();
}
