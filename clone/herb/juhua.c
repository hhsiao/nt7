#include "herb.h"

void create()
{
        set_name(HIY "菊花" NOR, ({ "ju hua", "ju", "hua", "herb_juhua" }));
        set("long", HIY "菊花是常見的中藥藥材。\n" NOR);
                set("base_unit", "朵");
                set("base_value", 60);
                set("base_weight", 20);
        setup();
}
