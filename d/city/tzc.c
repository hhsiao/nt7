#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIY+BLINK"挑戰擂臺"NOR);
        set("long", @LONG
[1；36m這裡是專門設來接受外國挑戰的擂臺。
LONG );
        set("no_drift", 1);
        set("no_clean_up", 0);
        set("exits",([
                "down" : "/d/city/guangchang",
        ]));

        setup();
        replace_program(ROOM);
}
