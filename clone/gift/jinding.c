// jinkuai.c 金塊

#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(YEL "金錠" NOR, ({ "jin ding", "jin", "ding" }));
        set_weight(2000);
        set("long", "一錠黃澄澄的金錠。\n");
                set("value", 800000);
                set("unit", "錠");
}

int query_autoload() { return 1; }
