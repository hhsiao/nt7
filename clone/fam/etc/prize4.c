#include <ansi.h>
inherit ITEM;

inherit F_LIQUID;

void create() {
    set_name(HIW "聖杯" NOR, ({ "god cup", "god", "cup" }));
    set_weight(1000);
    set("long", HIW "純銀所制的聖杯，似乎可以賣個好價錢。\n" NOR);
    set("unit", "隻");
    set("value", 500000);
    set("max_liquid", 100);
    set("liquid", ([
        "type": "water",
        "name": HIW "聖水" NOR,
        "remaining": 100,
        "drunk_supply": 100
        ]));
}

int query_autoload() {
    return 1;
}
