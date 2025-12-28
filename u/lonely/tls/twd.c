#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIY"天王殿"NOR);
        set("long", @LONG
穿過前院一段白石小路，登上七層石階，便是天王殿。殿內兩側
分立四大伏魔金剛，正中貢案上兩盞長明燈吐著雄雄火焰，一座尺餘
高的鐵鼎中香菸繚繞。東西兩邊是寺院的齋堂。
LONG);
        set("exits", ([             
               "southdown" : __DIR__"road",
               "northdown" : __DIR__"road1",                             
        ]));
        set("coor/x",-350);
  set("coor/y",-350);
   set("coor/z",30);
   setup();
}