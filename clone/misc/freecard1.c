// card.c
#include <ansi.h>;

inherit ITEM;

void create()
{
        set_name(HIC "三萬兩建房卡" NOR, ({"fee free card"}));
        set("unit", "張");
                set("long",HIC "這是一張價值三萬兩黃金的建房卡，把他交給魯班可以建相應價值的房屋。\n" NOR);
                set("value", 1);
                                set("fee free", 30000);
                set_weight(100);
        setup();
}

int query_autoload()
{
        return 1;
}
