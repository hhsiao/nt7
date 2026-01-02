// Room: /yangzhou/chongyanting.c
// Last Modified by Lonely on Jul. 20 2000

inherit ROOM;

void create() {
    set("short", "重簷亭");
    set("long",@LONG
熙春臺南側，有一重簷亭。湖石亭座，重簷六角，上覆鉻綠琉璃瓦
和寶頂。
LONG );
    set("outdoors", "shouxihu");
    set("exits", ([
        "north": __DIR__"pingtai5",
        "southeast": __DIR__"guanshaoting"
        ]));
    set("no_clean_up", 0);
    set("coor/x", -50);
    set("coor/y", 90);
    set("coor/z", 0);
    setup();
    replace_program(ROOM);
}
