// sifeng_kuanxue.c 四縫寬靴

#include <armor.h>

inherit BOOTS;

void create() {
    set_name("四縫寬靴", ({"sifeng kuanxue", "xie", "shoes"}));
    set_weight(1000);
    set("long", "一雙縫製精細的厚底布鞋，舒適合腳。\n");
    set("unit", "雙");
    set("value", 500);
    set("material", "cloth");
    set("armor_prop/armor", 3);
    set("armor_prop/dodge", 3);
    setup();
}
