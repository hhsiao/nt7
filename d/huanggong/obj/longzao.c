// longzao.c

inherit ITEM;
#include <ansi.h>;
void create()
{
        set_name(HIR"龍棗"NOR, ({"long zao"}));
        set_weight(700000);
        set("long", "一個株皇宮中的珍貴樹木。\n");
                set("unit", "株");
                set("no_get", 1);
}
