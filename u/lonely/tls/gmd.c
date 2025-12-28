#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIY"大光明殿"NOR);
        set("long",@LONG
這座大殿由四支大紅圓柱托住。殿上一個牌匾，上書“正法久住”
幾個楷書大字。殿裡供奉著阿彌陀佛及西方三聖。
LONG);       
        set("exits", ([
                "east" : __DIR__"yz3",
                "south" : __DIR__"sjt",
	]));
        set("coor/x",-360);
  set("coor/y",-290);
   set("coor/z",20);
   setup();
}