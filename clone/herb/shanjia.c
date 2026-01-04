#include "herb.h"

void create() {
    set_name(NOR + GRN "山甲" NOR, ({ "shan jia", "shan", "jia", "herb_shanjia" }));
    set("long", NOR + GRN "山甲是常見的中藥藥材。\n" NOR);
    set("base_unit", "片");
    set("base_value", 2000);
    set("base_weight", 60);
    setup();
}
