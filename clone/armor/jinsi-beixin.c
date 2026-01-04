
#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create() {
    set_name(HIY "金絲背心" NOR, ({ "jinsi beixin", "jinsi", "beixin" }) );
    set_weight(3000);
    set("unit", "件");
    set("material", "steel");
    set("value", 800000);
    set("armor_prop/armor", 500);
    set("limit", ([
        "exp": 500000,
        "int": 30
        ]));
    setup();
}

int query_autoload() {
    return 1;
}
