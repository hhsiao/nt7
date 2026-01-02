// This program is a part of NITAN MudLIB
// redl 2012/11/1
//商城物品，每輪闖關限制使用
#include <ansi.h>

inherit COMBINED_ITEM;

void create() {
    set_name(YEL"飛刀"HIC"靈符"NOR, ({ "fly knife", "knife", "fei dao" }) );
    set("long", NOR + WHT "這是一支楊小邪的飛刀，薄得近乎透明，上面還有一些亂七八糟的篆文，在靈感塔上可以使用它(use knife)。\n" NOR);
    set("base_unit", "支");
    set("base_value", 1000);
    set("base_weight", 600);
    set("unit", "疊");
    set("set_data", 1);     //下線不掉
    set("auto_load", 1);
    setup();
    set_amount(3);
}
