// trans_cart.c
//

#include <ansi.h>

inherit ITEM;

void create() {
    set_name(HIW "奔跑中……" NOR, ({ "running" }));
    set_weight(200000);
    set_max_encumbrance(1000000);
    set("running", 1);
    set("value", 1);
    set("long", "你正在快馬上奔跑 ……\n");
    set("unit", "次");
    set("material", "air");
    set("no_get", "!@#$!@#%%^@!^\n");
    setup();
}
