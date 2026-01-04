#include "herb.h"

void create() {
    set_name(HIY "藤黃" NOR, ({ "teng huang", "teng", "huang", "herb_tenghuang" }));
    set("long", HIY "藤黃是常見的中藥藥材。\n" NOR);
    set("base_unit", "包");
    set("base_value", 5000);
    set("base_weight", 50);
    setup();
}
