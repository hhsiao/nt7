inherit ITEM;
#include <ansi.h>

void create() {
    set_name(HIM "輪迴．烈火" NOR, ({"lunhui liehuo", "lunhui", "liehuo" }));
    set_weight(900);
    set("long", HIM "輪迴之苦．烈火焚身。\n" NOR);
    set("unit", "塊");
    set("value", 5000);
    set("enchase/name", "輪迴．烈火");
    set("enchase/point", 100);
    set("enchase/type", "all");
    set("enchase/cur_firm", 100);
    set("enchase/spe_data", ([]) );
    setup();
}

int query_autoload() {
    return 1;
}
