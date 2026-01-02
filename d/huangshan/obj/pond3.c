// pond3

#include <ansi.h>;
inherit ITEM;

void create() {
    set_name(BLK"烏池"NOR, ({ "wu chi", "chi", "wu" }) );
    set_weight(500);
    set_max_encumbrance(80000);
    set("no_get", 1);
    set("no_shown", 1);
    set("unit", "個");
    set("long", BLK"一個水色為烏的池潭。\n"NOR);
    set("value", 1);
}

int is_container() { return 1; }
