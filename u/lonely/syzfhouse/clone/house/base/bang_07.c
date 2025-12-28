
inherit "/inherit/room/house_base";

void create()
{
    set("short", "西山腳下");
    set("long", @LONG
西山龍門為西南一絕景，此處位於西山的山腳之下，一條崎嶇的
山路蜿蜒曲折，通向遠處好大的一片宅院，看上去似乎並非西山附近
常見的廟宇，而象是某個幫會的駐地所在。
LONG);

    set("exits",
    ([
        "east" : "/d/dali/xishan-lu",
    ]));

    set("outdoors", "dali");
    set("max_build", 1);
    set("can_build", "bang");

    setup();
    restore();
}
