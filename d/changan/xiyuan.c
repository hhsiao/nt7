//Room: xiyuan.c

inherit ROOM;

void create () {
    set ("short", "戲院");
    set("long", @LONG
這裡屋深幽暗，屋子西端搭有一座精巧但已有點退色的戲臺。戲
臺兩邊掛有數盞明亮的燈籠。前幾排有些矮凳，後面是一些紅油茶桌
和寬背扶手椅。
LONG );
    set("exits", ([
        "south": "/d/changan/liande-beikou"
        ]));
    set("objects", ([
        "/d/changan/npc/xizi" : 1
        ]));

    set("coor/x", -10680);
    set("coor/y", 1980);
    set("coor/z", 0);
    setup();
    replace_program(ROOM);
}
