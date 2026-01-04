#include "herb.h"

void create() {
    set_name(HIR "紅花" NOR, ({ "hong hua", "hong", "hua", "herb_honghua" }));
    set("long", HIR "紅花是常見的中藥藥材。\n" NOR);
    set("base_unit", "朵");
    set("base_value", 80);
    set("base_weight", 20);
    setup();
}
