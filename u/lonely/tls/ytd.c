#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIY"圓通殿"NOR);
        set("long",@LONG
眼前這座大殿極為宏偉。殿裡供奉著南無大慈大悲廣大靈感觀世
音菩薩，這殿中的千手觀音，隱然是用一塊大漢白玉精雕而成，鑲嵌
各種寶石，金銀，華麗之極，世間罕見，和寺中的三塔一樣被列為天
龍五寶之一，殿中香案上放著香客供的各種禮品。
LONG);       
        set("exits", ([
             "north" : __DIR__"xmd",
             "west" : __DIR__"yz6",
	]));

        set("coor/x",-340);
  set("coor/y",-300);
   set("coor/z",20);
   setup();
}