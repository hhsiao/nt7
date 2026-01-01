// x-drug.c

#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIB"陰"HIR"陽"HIG"和合散"NOR, ({ "yin yang san", "x-drug" }) );
        set_weight(80);
        set("taskobj", 1);
        set("long", "一種強烈的春藥。\n");
                set("unit", "包");
                set("value", 0);
}
