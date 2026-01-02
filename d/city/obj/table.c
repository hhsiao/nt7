// table.c

#include <ansi.h>

inherit ITEM;

void create() {
    set_name("石桌", ({ "table" }));
    set_weight(200000);
    set("long", "這是張大理石制的桌子。\n" );
    set("unit", "張");
    set("material", "stone");
    set("value", 2000);
    set("no_get", 1);
    set("amount", 30);
    setup();
}
