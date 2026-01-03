// rice.c

#include <ansi.h>

inherit ITEM;

void create() {
    set_name(YEL "手諭" NOR, ({ "pass" }) );
    set_weight(10);
        set("unit", "張");
        set("no_sell", 1);
        set("no_store", 1);
        set("material", "paper");
    set("long", "一張手諭。\n");
    setup();
}
