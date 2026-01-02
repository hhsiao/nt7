#include <ansi.h>

inherit ITEM;

void create() {
    set_name(HIG "綠菊花" NOR, ({ "lv juhua", "juhua" }));
    set("weight", 100);
    set("long", "一盆淡綠的菊花，叫做“春水碧波”。\n");
    set("unit", "盆");
    set("material", "wood");
    setup();
}
