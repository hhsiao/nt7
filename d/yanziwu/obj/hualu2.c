// hualu2.c
#include <ansi.h>;
inherit ITEM;

void create() {
    set_name(HIW"茉莉花露"NOR, ({ "hua lu" }));
    set_weight(1500);
    set("long", "這是一瓶茉莉花露，看來是花了不少心血泡製成的。\n");
    set("unit", "瓶");
    set("value", 50);
}
