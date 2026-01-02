//redl 2014
inherit __DIR__"normal.c";

void create() {
    int rnd = random(100);
    set("short", "九老洞");
    set("long", @LONG
這就是峨嵋第一大洞，洞內深窈無比，神秘難測。你一走進來，
便發覺洞中叉叉洞多如迷宮，怪異莫測，似乎黝黑無底。洞裡隱隱傳
來雞犬鼓樂之聲，令人驚異間，忽有蝙蝠群湧而至撲熄火炬。還是快
快離開吧。
LONG );
    /*
     * set("objects", ([
     * __DIR__"npc/bianfu1" : 10,
     * ]));*/
    set("exits", ([
        "enter": __DIR__"bfdc0",
        "south": __DIR__"bfdb" + (string)random(30),
        "north": __DIR__"bfdb" + (string)random(30),
        "west": __DIR__"bfdb" + (string)random(30),
        "east": __DIR__"bfdb" + (string)random(30),
        "up": __DIR__"bfdb" + (string)random(30),
        "down": __DIR__"bfdb" + (string)random(30)
        ]));

    set("n_time", 30 + random(10));
    set("n_npc", 1 + random(3));
    set("n_max_npc", 5 + random(4));
    if (rnd<10)
        set("s_npc", "/d/emei/xue/npc/bianfu4");
    else if (rnd<30)
        set("s_npc", "/d/emei/xue/npc/bianfu3");
    else
        set("s_npc", "/d/emei/xue/npc/bianfu2");
    setup();

    set("stop_run", random(10));
    setup();
}
