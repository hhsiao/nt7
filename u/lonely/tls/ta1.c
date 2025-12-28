#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIW"千尋寶塔"NOR);
        set("long",@LONG
崇聖寺三塔主塔千尋居中，是三塔中最高的一座，共有十六層，
高三百餘尺，與西安大小雁塔同是唐代密簷式建築。塔下仰望，只見
塔矗雲端，雲移塔駐似有傾倒之勢。塔的基座呈方形，分二層，下層
四周有石欄，欄的四角柱頭雕有石獅；上層東面正中有石照壁，上有
黔國公沐英後裔灑世階題的“永鎮山川”四個大字，莊重雄奇，頗有
氣魄。每層正面中央開卷龕，各置白色大理石佛像一尊。
LONG);
        set("outdoors", "天龍寺");
        set("exits", ([
                "south" : __DIR__"yz6",
                "north" : __DIR__"yz3",		
        ]));
	
        set("coor/x",-350);
  set("coor/y",-300);
   set("coor/z",20);
   setup();
}
