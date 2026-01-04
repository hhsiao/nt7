#include <ansi.h>

inherit COMBINED_ITEM;
#include "meat.h"

void create() {
    set_name(NOR + WHT "虎肉" NOR, ({ "hu rou", "hu", "rou" }));
    set("long", NOR + WHT "這是一塊散發著腥臊臭的虎肉。\n" NOR);
    set("base_unit", "塊");
    set("base_value", 120);
    setup();
    set_amount(1);
}
