#include <ansi.h>

inherit ITEM;

void create() {
    set_name(NOR + WHT "蠶絲" NOR, ({ "can si", "can", "si" }));
    set("long", NOR + WHT "這是一根普通的蠶絲。\n" NOR);
    set("base_unit", "根");
    set("unit", "根");
    set("base_value", 1000);
    set("base_weight", 1);
    setup();
}
int query_autoload() {
    return 1;
}
