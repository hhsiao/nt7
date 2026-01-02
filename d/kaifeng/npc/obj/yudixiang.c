#include <ansi.h>
inherit ITEM;

void create() {
    set_name(HIW "白玉雕玉皇像" NOR, ({ "xiang" }) );
    set_weight(500000);
    set_max_encumbrance(800);
    set("unit", "座");
    set("long", "玉帝手持玉版，端坐微笑不語。\n");
    set("value", 50);
}
