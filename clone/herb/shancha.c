#include "herb.h"

void create() {
    set_name(NOR + WHT "山茶" NOR, ({ "shan cha", "chan", "cha", "herb_shancha" }));
    set("long", NOR + WHT "山茶是常見的中藥藥材。\n" NOR);
    set("base_unit", "朵");
    set("base_value", 200);
    set("base_weight", 20);
    setup();
}
