
inherit "/inherit/room/house_base";

void create()
{
    set("short", "蓮蓉橋堍");
    set("long", @LONG
蓮蓉橋堍頗為空曠，並無多少建築，行人也甚是稀少。官道之旁
卻有一條岔路，延伸向西首，路的盡頭有好大一片宅院，看上去似乎
是某個幫會的駐地所在。
LONG);

    set("exits",
    ([
        "east"  : "/d/wuxi/qiao4",
    ]));

    set("outdoors", "wuxi");
    set("max_build", 1);
    set("can_build", "bang");

    setup();
    restore();
}
