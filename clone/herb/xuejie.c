#include "herb.h"

void create() {
    set_name(NOR + RED "血竭" NOR, ({ "xue jie", "xue", "jie", "herb_xuejie" }));
    set("long", NOR + RED "血竭是常見的中藥藥材。\n" NOR);
    set("base_unit", "塊");
    set("base_value", 200);
    set("base_weight", 40);
    setup();
}
