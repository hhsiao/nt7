// #pragma save_binary

#include <weapon.h>
#include <ansi.h>
inherit SWORD;

void create() {
    set_name(WHT "斷了的倚天劍" NOR, ({ "duan jian", "sword" }) );
    set_weight(10000);
    set("unit", "柄");
    set("long", "一柄斷了的長劍\n");
    set("value", 0);
    set("rigidity", 8000);
    set("material", "steel");
    init_sword(1);
    setup();
}
