// jinpao.c
// Last Modified by Lonely on May. 25 2001

#include <armor.h>
inherit CLOTH;

void create() {
    set_name("錦花袍", ({"jinhua pao", "cloth", "pao"}));
    set_weight(1000);
    set("unit", "件");
    set("long",
        "這是一件華貴無比的錦花袍，上面繡著各種花草，還有一股香氣．\n");
    set("value", 5000);
    set("material", "cloth");
    set("armor_type", "cloth");
    set("armor_prop/armor", 10);
    set("armor_prop/per", 3);
    setup();
}
