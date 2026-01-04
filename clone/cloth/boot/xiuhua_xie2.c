// xiuhua_xie2.c

#include <ansi.h>
#include <armor.h>
inherit BOOTS;
void create() {
    set_name(GRN "蔥綠繡花鞋" NOR, ({"xiuhua xie", "xie", "shoes"}));
    set_weight(1000);
    set("unit", "雙");
    set("value", 1000);
    set("material", "grass");
    set("armor_prop/armor", 1);
    set("female_only", 1);
    set("armor_prop/personility", 3);
    setup();
}
