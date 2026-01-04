#include <ansi.h>
#include <armor.h>

inherit WAIST;

void create() {
    set_name(HIR "聖靈腰帶" NOR, ({ "shengling belt3", "belt", "shengling3" }));
    set_weight(100);
    set("long", HIW "一根閃耀著奇異光芒的腰帶。\n" NOR);
    set("unit", "根");
    set("value", 400000);
    set("armor_prop/armor", 100);
    set("armor_prop/dodge", 12);
    set("armor_prop/parry", 14);
    setup();
}

int query_autoload() {
    return 1;
}
