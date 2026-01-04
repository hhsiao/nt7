
#include <armor.h>
#include <ansi.h>

inherit ARMOR;

void create() {
    set_name(HIB "黑鐵鎧" NOR, ({ "heitie kai3", "heitie", "kai3" }) );
    set_weight(30000);
    set("unit", "件");
    set("material", "steel");
    set("value", 800000);
    set("armor_prop/armor", 700);
    set("limit", ([
        "exp": 15000000,
        "str": 60
        ]));
    setup();
}

int query_autoload() {
    return 1;
}
