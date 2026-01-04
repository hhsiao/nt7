// /clone/armor/guanxue.c   官靴 -3

#include <armor.h>
#include <ansi.h>

inherit BOOTS;
void create() {
    set_name(HIW"官靴"NOR, ({ "guan xue", "xue", "shoes" }));
    set_weight(150);
    set("long", "這是一雙朝廷官員慣用的官靴。\n");
    set("unit", "雙");
    set("no_transfer", 1);
    set("material", "cloth");
    set("armor_type", "feet");
    set("armor_prop/dodge", 2);
    setup();
}
