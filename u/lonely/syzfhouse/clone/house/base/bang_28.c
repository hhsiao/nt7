
inherit "/inherit/room/house_base";

void create()
{
    set("short", "鑽天坡");
    set("long", @LONG
此處背依“一線天”，坡勢甚緩，古木參天自成一林。燕雀歡鳴
林間，流泉飛瀑林外。林中淺霧略現迷濛，一條穿林小徑曲折通向樹
林深處。林深處依稀見一座青磚黛瓦的大宅院，似為某個幫會駐地之
所在。
LONG);

    set("exits",
    ([
        "east"  : "/d/emei/taohua-wu",
    ]));

    set("outdoors", "emei");
    set("max_build", 1);
    set("can_build", "bang");

    setup();
    restore();
}
