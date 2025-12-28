
inherit "/inherit/room/house_base";

void create()
{
    set("short", "川中驛道");
    set("long", @LONG
這是通往成都的大驛道之側，路邊是豐沃的良田，種著各種各樣
的莊稼，經常能看到農民在田裡辛勤的工作。向南遙望，隱隱可見有
一大片宅院，看上去似乎是某個幫會的駐地所在。
LONG);

    set("exits",
    ([
        "northeast" : "/d/sichuan/yidao1",
    ]));

    set("outdoors", "sichuan");
    set("max_build", 1);
    set("can_build", "bang");

    setup();
    restore();
}
