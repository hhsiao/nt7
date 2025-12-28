#include <ansi.h>
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", HIG"小巷內"NOR);
        set("long", @LONG
這裡是京城街頭的小巷，裡面三三兩兩來往著些著裝怪異的人群，你忍不住朝
其中的一位多看了兩眼，只見對方滿臉兇橫，看來還是少惹為妙，趕快離開的好。
LONG
        );
        set("indoors", "city");
        set("exits", ([
                "northeast"  :  __DIR__"dadao9",
                "southeast"  :  __DIR__"dadao10",
                "northwest"  :  __DIR__"dadao15",
                "southwest"  :  __DIR__"dadao16",
        ]));
        set("no_fly",1);
        setup();
        replace_program(ROOM);
}

