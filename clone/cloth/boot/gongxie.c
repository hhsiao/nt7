// gongxie.c

#include <armor.h>
inherit BOOTS;
void create() {
    set_name("弓鞋", ({"gong xie", "xie", "shoes"}));
    set_weight(1000);
    set("long", "一雙窄窄的弓鞋，武林中的俠女們的腳下物。\n");
    set("unit", "雙");
    set("value", 100);
    set("material", "silk");
    set("armor_prop/armor", 1);
    set("armor_prop/dodge", 4);
    set("female_only", 1);
    setup();
}
