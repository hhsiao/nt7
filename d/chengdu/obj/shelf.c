#include <ansi.h>
inherit ITEM;

#define QIPU    "/clone/item/xiaoao/ouxuepu"

void create() {
    object ob;
    set_name(WHT "破爛的書架" NOR, ({ "shelf" }) );
    set_weight(5000000);
    set_max_encumbrance(800000);
    ob = find_object(QIPU);
    if (! ob) ob = load_object(QIPU);
    if (! environment(ob))
        ob->move(this_object());

    set("prep", "in");
    set("unit", "只");
    set("long", WHT "一隻破爛的書架，腐朽不堪，也不知擱在這裡多久了。\n" NOR);
    set("value", 1);
    set("no_get", 1);
}

int is_container() {
    return 1;
}
