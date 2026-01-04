#include <ansi.h>

inherit ITEM;

void create() {
    set_name(HIC "海貝殼" NOR, ({ "haibei ke", "haibei", "ke" }));
    set("long", HIC "一塊巨大的海貝殼，似乎可找工匠做成飾品。\n" NOR);
    set("base_unit", "塊");
    set("unit", "塊");
    set("base_value", 10000);
    set("base_weight", 600);
    setup();
}
int query_autoload() {
    return 1;
}
