#include <ansi.h>

inherit COMBINED_ITEM;
#include "meat.h"

void create()
{
        set_name(NOR + WHT "牛肉" NOR, ({ "niu rou", "niu", "rou" }));
        set("long", NOR + WHT "這是一塊散發著腥臊臭的牛肉。\n" NOR);
                set("base_unit", "塊");
                set("base_value", 40);
        setup();
        set_amount(1);
}
