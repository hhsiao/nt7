#include <ansi.h>

inherit COMBINED_ITEM;
#include "meat.h"

void create() {
    set_name(NOR + WHT "狸肉" NOR, ({ "li rou", "li", "rou" }));
    set("long", NOR + WHT "這是一塊散發著腥臊臭的狐狸肉。\n" NOR);
    set("base_unit", "塊");
    set("base_value", 50);
    setup();
    set_amount(1);
}
