// hat.c example belt

#include <ansi.h>

inherit EQUIP;

void create() {
    set_name(HIY "纓子帽" NOR, ({ "yingzi mao", "yingzi", "mao" }) );
    set_weight(1000);
    set("unit", "頂");
    set("value", 300);
    set("material", "cloth");
    set("armor_type", "head");
    set("armor_prop/armor", 4);
    set("armor_prop/dodge", -1);
    set("wear_msg", "$N戴上一頂$n。\n");
    set("remove_msg", "$N將$n脫了下來。\n");

    setup();
}
