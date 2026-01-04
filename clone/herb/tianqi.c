#include "herb.h"

void create() {
    set_name(NOR + WHT "田七" NOR, ({ "tian qi", "tian", "qi", "herb_tianqi" }));
    set("long", NOR + WHT "田七是常見的中藥藥材。\n" NOR);
    set("base_unit", "根");
    set("base_value", 400);
    set("base_weight", 55);
    setup();
}
