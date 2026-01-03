
inherit ROOM;

void create() {
    set("short", "漁村曬網場南");
    set("long", @LONG
小村不大，卻有個好大的曬網場。幾個小孩在場中無憂地玩耍，
聲音喧鬧。靠南海邊上，有個漁夫面向大海，悠然垂釣。
LONG );
    set("outdoors", "nanhai");
    set("exits", ([
        "north": __DIR__"xkroad5"
        ]));
    set("objects", ([
        __DIR__"npc/boy": 1,
        __DIR__"npc/girl": 1,
        __DIR__"npc/yufu": 1,
        "/kungfu/class/misc/haigui" : 1
        ]));
    setup();
    replace_program(ROOM);
}
