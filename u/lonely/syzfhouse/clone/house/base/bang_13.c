
inherit "/inherit/room/house_base";

void create()
{
    set("short", "安定門外");
    set("long", @LONG
安定門外是一條寬闊筆直的大道，通向北京城外的遠方，路上的
景色顯得蕭瑟得許多，那是進入更北方的顯兆。回頭看看南方，還能
看見北京城高大的城牆和門樓。道旁有一片宅院，看上去似乎是某個
幫會的駐地所在。
LONG);

    set("exits",
    ([
        "east" : "/d/shanhai-guan/guandao1",
    ]));

    set("outdoors", "beijing");
    set("max_build", 1);
    set("can_build", "bang");

    setup();
    restore();
}
