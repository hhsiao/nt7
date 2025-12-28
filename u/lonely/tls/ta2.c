#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIW"無相寶塔"NOR);
        set("long",@LONG
崇聖寺三塔東塔無相，高二百餘尺，八角十層，皆為實心，各層
分別雕卷龕、佛像、蓮花等，華貴莊重。正面中央開卷龕，各置白色
大理石佛像一尊。
LONG);
        set("outdoors", "天龍寺");
        set("exits", ([
                "south" : __DIR__"yz4",
        ]));	
        set("coor/x",-330);
  set("coor/y",-310);
   set("coor/z",30);
   setup();
}
