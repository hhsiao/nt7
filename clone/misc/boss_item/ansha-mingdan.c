inherit ITEM;
#include <ansi.h>

void create() {
    set_name(HIR "暗殺名單" NOR, ({"ansha mingdan", "ansha", "mingdan"}));
    set_weight(2000);
    set("unit", "份");
    set("long", HIR "這是一份寫有朝廷要員名字的暗殺名單。\n"  NOR);

    set("value", 500000);
    setup();
}

int query_autoload() {
    return 1;
}
