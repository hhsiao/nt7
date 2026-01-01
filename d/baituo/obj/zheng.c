// zheng.c

#include <ansi.h>
#include <music.h>

inherit ITEM;
inherit MI_ZHENG;

void create()
{
        set_name("古箏", ({ "gu zheng", "gu", "zheng" }));
        set_weight(300);

        set("unit", "臺");
                set("long", YEL "這是一臺看上去有些陳舊的古箏。\n" NOR);
                set("value", 50);
                set("material", "wood");
        setup();
}

void init()
{
        add_action("play_zheng", "play");
}
