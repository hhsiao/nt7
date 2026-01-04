#include "herb.h"

void create() {
    set_name(HIW "燕窩" NOR, ({ "yan wo", "yan", "wo", "herb_yanwo" }));
    set("long", HIW "雪燕在峭壁所制的窩巢，乃是極為名貴的中藥藥材。\n");
    set("base_unit", "塊");
    set("base_value", 50000);
    set("base_weight", 35);
    setup();
}
