
inherit "/inherit/room/house_base";

void create()
{
    set("short", "軍鎮外");
    set("long", @LONG
這裡是軍鎮外的荒原空地，地上寥落長著些灌木枯草。不遠處列
一排高大挺立的白樺樹。在陣陣北風中，彷彿能聽見枝頭枯葉沙沙作
響。白樺樹後現出一座大宅院，儼然是江湖中哪個幫會的駐地。
LONG);

    set("exits",
    ([
        "east"  : "/d/shanhai-guan/junzheng",
    ]));

    set("outdoors", "shanhai-guan");
    set("max_build", 1);
    set("can_build", "bang");

    setup();
    restore();
}
