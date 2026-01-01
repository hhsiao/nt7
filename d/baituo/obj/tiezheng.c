// tiezheng.c

#include <ansi.h>
#include <music.h>

inherit ITEM;
inherit MI_ZHENG;

void create()
{
        set_name(NOR + WHT "鐵箏" NOR, ({ "tie zheng", "tie", "zheng" }));
        set_weight(300);

        set("unit", "臺");
                set("long", WHT "這是一臺黑黝黝的鐵箏。\n" NOR);
                set("value", 5000);
                set("material", "steel");
        setup();
}

void init()
{
        add_action("play_zheng", "play");
}
