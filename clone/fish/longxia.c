// longxia.c 龍蝦

inherit ITEM;

#include <ansi.h>
#include "xia.h";

void create()
{
        set_name("龍蝦", ({ "long xia", "longxia" }) );
        set("long", "一隻威武的大龍蝦。\n");
                set("unit", "只");

        setup();
}
