#include <armor.h>
#include <ansi.h>

inherit RINGS;

void create() {
    set_name(HIC "藍色妖姬" NOR, ({ "lanyao ring", "lanyao", "ring" }));
    set_weight(500);
    set("unit", "個");
    set("long", HIC "藍色妖姬乃神秘的化身，象徵著「智慧」！\n" NOR);
    set("value", 200000);
    set("material", "gold");
    set("armor_prop/int", 10);
    set("armor_prop/damage", 200);
    setup();
}

int query_autoload() {
    return 1;
}
