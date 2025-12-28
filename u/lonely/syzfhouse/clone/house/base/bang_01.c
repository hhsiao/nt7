
inherit "/inherit/room/house_base";

void create()
{
    set("short", "惠山峰腰");
    set("long", @LONG
此處位於惠山峰腰東側，山路曲曲折折，滿山青松綽約，四周花
草成叢，林蔭茂盛。綠樹掩映間，隱隱可見有好大一片宅院，似乎是
某個幫會的駐地所在。
LONG);

    set("exits",
    ([
        "west"  : "/d/wuxi/shanlu",
    ]));

    set("outdoors", "wuxi");
    set("max_build", 1);
    set("can_build", "bang");

    setup();
    restore();
}
