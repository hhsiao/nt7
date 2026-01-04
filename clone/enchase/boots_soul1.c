
#include <ansi.h>

inherit EQUIP_SOUL;

void create() {
    set_name(HIM "戰靴之魂" NOR, ({"boots soul1", "boots", "soul1"}));
    set_weight(100);

    set("long", HIM "這是一個戰靴之魂。\n" NOR);
    set("unit", "個");
    set("value", 200000);
    set("no_sell", 1);

    set("type", "boots");
    set("status", 1);
    set("auto_load", 1);

    setup();
}
