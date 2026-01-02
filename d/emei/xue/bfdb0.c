//redl 2014
inherit __DIR__"normal.c";

void create() {
    set("short", "九老洞");
    set("long", @LONG
這就是峨嵋第一大洞，洞內深窈無比，神秘難測。你一走進來，
便發覺洞中叉叉洞多如迷宮，怪異莫測，似乎黝黑無底。洞裡隱隱傳
來雞犬鼓樂之聲，令人驚異間，忽有蝙蝠群湧而至撲熄火炬。還是快
快離開吧。
LONG );
    set("objects", ([
        __DIR__"npc/jianxia" : 1
        ]));
    set("exits", ([
        "out": __DIR__"bfd29",
        "south": __DIR__"bfdb" + (string)random(30),
        "north": __DIR__"bfdb" + (string)random(30),
        "west": __DIR__"bfdb" + (string)random(30),
        "east": __DIR__"bfdb" + (string)random(30),
        "up": __DIR__"bfdb" + (string)random(30),
        "down": __DIR__"bfdb" + (string)random(30)
        ]));

    set("n_time", 14400);
    set("n_npc", 1);
    set("n_max_npc", 1);
    set("s_npc", "/d/emei/xue/npc/yu");
    set("stop_run", random(10));
    setup();
}


void init() {
    object me = this_player();
    //不改short_name是為了避免玩家利用walk指令過迷宮
    tell_object(me, "\n你來到了九老洞第二層的入口。\n\n");
    return ::init();
}
