#include "herb.h"

void create()
{
        set_name(NOR + MAG "桃仙" NOR, ({ "tao xian", "tao", "xian", "herb_taoxian" }));
        set("long", NOR + MAG "桃仙是常見的中藥藥材。\n" NOR);
                set("base_unit", "塊");
                set("base_value", 5000);
                set("base_weight", 40);
        setup();
}
