//redl 2014
inherit BUILD_ROOM;

void create() {
    set("short", "九老洞");
    set("long", @LONG
這就是峨嵋第一大洞，洞內深窈無比，神秘難測。你一走進來，
便發覺洞中叉叉洞多如迷宮，怪異莫測，似乎黝黑無底。洞裡隱隱傳
來雞犬鼓樂之聲，令人驚異間，忽有蝙蝠群湧而至撲熄火炬。還是快
快離開吧。
LONG );
    set("objects", ([
        __DIR__"npc/bianfu1" : (random(5) ? 0 : (random(7) + 3))
        ]));
    set("exits", ([
        "out": "/d/emei/jldongnei",     //獨有0開放此行
        "south": __DIR__"bfd" + (string)random(30),
        "north": __DIR__"bfd" + (string)random(30),
        "west": __DIR__"bfd" + (string)random(30),
        "east": __DIR__"bfd" + (string)random(30),
        "up": __DIR__"bfd" + (string)random(30),
        "down": __DIR__"bfd" + (string)random(30),
    /*
     * "southup" : __DIR__"bfd" + (string)random(20),
     * "northup" : __DIR__"bfd" + (string)random(20),
     * "westup" : __DIR__"bfd" + (string)random(20),
     * "eastup" : __DIR__"bfd" + (string)random(20),
     * "southdown" : __DIR__"bfd" + (string)random(20),
     * "northdown" : __DIR__"bfd" + (string)random(20),
     * "westdown" : __DIR__"bfd" + (string)random(20),
     * "eastdown" : __DIR__"bfd" + (string)random(20),
     * "southwest" : __DIR__"bfd" + (string)random(20),
     * "southeast" : __DIR__"bfd" + (string)random(20),
     * "northwest" : __DIR__"bfd" + (string)random(20),
     * "northeast" : __DIR__"bfd" + (string)random(20),*/
        ]));

    set("stop_run", random(12));
    setup();
}


int valid_leave(object me, string dir) {
    if (me->is_fighting())
    {
        tell_object(me, "你還是先解決目前的敵人吧！\n");
        return 0;
    }

    return ::valid_leave(me, dir);
}


void init() {
    if (query("stop_run") ) return;
    if (query("env/invisible", this_player()) ) return;
    tell_object(this_player(), "\n噗哧一聲你踩到坨蝙蝠屎，差點跌倒！\n\n");
    this_player()->start_busy(2);
}
