#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIW"初級經脈學"NOR, ({ "jingmai book", "book", "shu" }) );
        set("unit", "本");
                set("value", 5000);
                set_weight(10);
                set("material", "paper");
                set("skill", ([
                        "name": "jingmai-xue",
                        "jing_cost":    10,
                        "difficulty":   25,
                        "min_skill":    0,
                        "max_skill":    40
                ]) );
        setup();
}
