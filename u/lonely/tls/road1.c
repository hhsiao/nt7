#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIW"白石路"NOR);
        set("long", @LONG
這裡又是一段白石路，連接著前面的大雄寶殿後後面的天王殿，
石面平滑，打掃得乾乾淨淨。抬眼一看，雪巒萬仞，鏤銀灑翠的點蒼
山峙其後，波濤萬頃、橫練蓄黛的洱海嵌於前。寺內三塔鼎峙，撐天
拄地；玉柱標空，雄渾壯麗，為蒼洱間的勝景之一。
LONG);
        set("outdoors", "dali");

        set("exits", ([             
               "southup" : __DIR__"twd",
               "northup" : __DIR__"baodian",     
               "east" : __DIR__"gulou",
               "west" : __DIR__"zhonglou",

        ]));
        set("objects",([
                __DIR__"npc/guest" : 1,
				 __DIR__"npc/xin-qing" : 1,
        ]));


        set("coor/x",-350);
  set("coor/y",-340);
   set("coor/z",20);
   setup();
}