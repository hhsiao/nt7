// 辟穀符

#include <ansi.h>

inherit ITEM;

void create() {
    set_name(HIW "辟穀符" NOR, ({ "bigu fu", "fu" }) );
    set_weight(30);

    set("long", HIW "攜帶後進入沙漠地帶不會因為無食物飲水而暈倒。\n" NOR);
    set("value", 1);
    set("no_sell", 1);
    set("unit", "張");
    set("auto_load", 1);

    setup();
}
