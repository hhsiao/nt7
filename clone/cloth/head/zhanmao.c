// zhanmao.c

#include <armor.h>
#include <ansi.h>
inherit HEAD;
void create() {
    set_name(HIR"紅纓氈帽"NOR, ({ "hongying zhanmao", "head" }) );
    set_weight(100);
    set("unit", "頂");
    set("value", 700);
    set("material", "cloth");
    set("armor_prop/armor", 1);
    setup();
}
