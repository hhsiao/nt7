#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIW"進階經脈學"NOR, ({ "jingmai book", "book", "shu" }) );
        set("unit", "本");
                set("value", 8000);
                set_weight(10);
                set("material", "paper");
                set("skill", ([
                        "name": "jingmai-xue",
                        "jing_cost":    15,
                        "difficulty":   25,
                        "min_skill":    40,
                        "max_skill":    80
                ]) );
        setup();
}
