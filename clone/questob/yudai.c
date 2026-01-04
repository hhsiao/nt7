// yudai.c

#include <ansi.h>

inherit ITEM;

void create() {
    set_name("玉帶", ({ "yu dai" }));
    set_weight(500);
    set("unit", "條");
    set("long", "這是一條玉帶，上面繡得五彩繽紛，頗為美麗。\n");
    set("value", 10000);
    set("material", "silk");
    setup();
}
