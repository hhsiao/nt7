#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "山路");
        set("long", @LONG
這是條應樂峰以北山腳下的山路，路面用青磚鋪成，每隔四五步又有
一匹由漢白玉製長磚，看來著實花了不少功夫。前面有一片斑竹林子，遙
現紅牆和三座高塔，隨風隱隱傳來一陣寺院的鐘聲和佛門檀香香味。
LONG);
        set("outdoors", "dali");

        set("exits", ([             
               "south" : __DIR__"ylf2",
               "north" : __DIR__"gate",
        ]));
set("objects",([
                __DIR__"npc/duan-m" : 2,
        ]));

        set("coor/x",-350);
  set("coor/y",-370);
   set("coor/z",20);
   setup();
}