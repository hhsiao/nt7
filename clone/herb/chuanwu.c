#include "herb.h"

void create()
{
        set_name(NOR + WHT "川烏" NOR, ({ "chuan wu", "chuan", "wu", "herb_chuanwu" }));
        set("long", NOR + WHT "川烏是常見的中藥藥材。\n" NOR);
                set("base_unit", "根");
                set("base_value", 200);
                set("base_weight", 50);
        setup();
}
