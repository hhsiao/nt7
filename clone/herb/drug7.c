#include "herb.h"

void create() {
    set_name("七品龍丹", ({ "dragon soul", "herb_drug7" }) );
    set("long", "這是龍的內丹，雞蛋大小，如火焰般赤紅。用法：boost\n");
    set("base_unit", "顆");
    set("base_value", 50000);
    set("base_weight", 5);
    setup();
}
