inherit ITEM;
#include <ansi.h>

void create() {
    set_name(HIM "輪迴．修羅" NOR, ({"lunhui xiuluo", "lunhui", "xiuluo" }));
    set_weight(900);
    set("long", HIM "輪迴之苦．修羅滅之。\n" NOR);
    set("unit", "塊");
    set("value", 5000);
    set("enchase/name", "輪迴．修羅");
    set("enchase/point", 95);
    set("enchase/type", "all");
    set("enchase/cur_firm", 85);
    set("enchase/spe_data", ([]) );
    setup();
}

int query_autoload() {
    return 1;
}
