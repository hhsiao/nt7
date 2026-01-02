//象棋室
// redl 2013/2

#include <ansi.h>
inherit  ROOM;

string look_string();

void create  () {
    set  ("short", "象棋室");
    set("long", @LONG
這裡是下中國象棋的靜室，牆上貼著“觀棋不語真君子，輸錢不痛大丈夫”。
在房間中央的柱子上還貼著一張下棋指南(help 或者 ?)，觀棋(look ccb)。
LONG );

    set("no_dazuo", 1);
    set("no_kill", 1);
    set("no_fight", 1);
    set("no_steal", 1);
    set("no_beg", 1);


    set("exits", ([
    //    "east"  :  __DIR__"qiyuan2",
    //    "south"  :  __DIR__"qiyuan3",
        "north": __DIR__"xxzl1",
    //    "west" : "/d/city/kedian4"
        ]));

    set("objects", ([
        __DIR__"cch2": 1
        ]));
    setup();
}
