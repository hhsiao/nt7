#include "herb.h"

void create()
{
        set_name(NOR + CYN "幹石榴" NOR, ({ "gan shiliu", "gan", "shiliu", "herb_gsliu" }));
        set("long", NOR + CYN "幹石榴是常見的中藥藥材。\n" NOR);
                set("base_unit", "片");
                set("base_value", 200);
                set("base_weight", 75);
        setup();
}
