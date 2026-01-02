#include <room.h>
#include <ansi.h>
inherit ROOM;

void create() {
    set("short", HIY"地安門廣場"NOR);
    set("long", @LONG
這裡就是地安門廣場，灰色的城牆給人以莊嚴肅穆之感，往北通
過紫禁城的地安門就是城郊了。遠遠望去，紫禁城的輪廓益發顯得雄
偉高大，一條護城河繞城而過。一條筆直的青石大道橫貫東西，東邊
是地安門東街廣場，西邊是地安門西街廣場。南邊通過一條小橋就是
皇宮的北門了。[2；37；0m
LONG );
    set("exits", ([
        "south": "/d/beijing/hgmen_n",
        "north": "/d/beijing/di_dajie1",
        "west": "/d/beijing/di_xigc",
        "east": "/d/beijing/di_donggc"
        ]));
    set("objects", ([
        "/d/beijing/npc/bing1" : 2,
        "/d/beijing/npc/bing3" : 1,
        "/d/beijing/npc/old2" : 1,
        "/d/beijing/npc/kid1" : 1,
        "/clone/npc/walker"  : 1
        ]));
    set("outdoors", "beijing");
    set("coor/x", -2800);
    set("coor/y", 7720);
    set("coor/z", 0);
    setup();
    replace_program(ROOM);
}
