#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIY"須彌殿"NOR);
        set("long",@LONG
這座殿堂規模較小，但香霧繚繞，人來人往，很是熱鬧，殿內供奉
著五百羅漢，佛像金身金衣，或笑口大開，或斜靠坐著，或怒目而視，
各不相同。許多香客都在數著羅漢，看哪尊會和自己有源。
LONG);       
        set("exits", ([
                "west" : __DIR__"yz3",
                "south" : __DIR__"ytd",
	]));

        set("coor/x",-340);
  set("coor/y",-290);
   set("coor/z",20);
   setup();
}