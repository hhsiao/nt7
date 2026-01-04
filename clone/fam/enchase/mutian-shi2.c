inherit ITEM;
#include <ansi.h>

void create() {
    set_name(HIW "幕天石" NOR, ({"mutian shi", "mutian", "shi"}));
    set_weight(2000);
    set("unit", "顆");
    set("value", 500000);
    set("enchase/name", "幕天石");
    set("enchase/point", 100);
    set("enchase/type", "waist");
    set("enchase/cur_firm", 100);
    set("nine_object", 1);  // 九孔鑲嵌物品標記
    set("enchase/spe_data", ([]) );
    setup();
}

int query_autoload() {
    return 1;
}
