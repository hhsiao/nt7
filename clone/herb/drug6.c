#include "herb.h"

void create()
{
        set_name("六品龍丹", ({ "dragon soul", "herb_drug6" }) );
        /*if( clonep() )
                set_default_object(__FILE__);
        else*/ {
                set("long","這是龍的內丹，雞蛋大小，如火焰般赤紅。用法：boost\n");
                set("base_unit", "顆");
                set("base_value", 50000);
                set("base_weight", 5);
        }
        setup();
}

