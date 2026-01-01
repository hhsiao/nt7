#include <ansi.h>

inherit COMBINED_ITEM;
#include "meat.h"

void create()
{
        set_name(NOR + WHT "豹肉" NOR, ({ "bao rou", "bao", "rou" }));
        set("long", NOR + WHT "這是一塊散發著腥臊臭的豹肉。\n" NOR);
                set("base_unit", "塊");
                set("base_value", 100);
        setup();
        set_amount(1);
}
