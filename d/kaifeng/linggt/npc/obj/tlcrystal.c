// This program is a part of NITAN MudLIB
// redl 2012/12/1
//商城物品，每輪闖關限制使用，延長闖關時間30秒
#include <ansi.h>

inherit COMBINED_ITEM;

void create()
{
                set_name(HIC"塔靈"HIM"水晶"NOR, ({"tower crystal", "crystal", "tower"}) );
                set("long", NOR + WHT "這是一塊塔靈凝練出的水晶，蘊含著強大的時間之力。在靈感塔上可以使用它(use crystal)。\n" NOR);
                        set("base_unit", "塊");
                        set("base_value", 1000);
                        set("base_weight", 600);
                        set("unit", "堆");
                set("set_data", 1); //下線不掉
                set("auto_load", 1);
                setup();
                set_amount(1);
}
