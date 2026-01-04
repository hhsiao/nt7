// thousand.c

#include <ansi.h>

inherit MONEY;

void create() {
    set_name(YEL "一千兩金票" NOR, ({"thousand-gold", "thousand-gold_money"}));
    set("money_id", "thousand-gold");
    set("long", "一張面額值一千兩金子的金票。\n");
    set("unit", "疊");
    set("base_value", 10000000);
    set("base_unit", "張");
    set("base_weight", 6);
    set_amount(1);
}
