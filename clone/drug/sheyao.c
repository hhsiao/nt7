// Code of ShenZhou
#include <ansi.h>

inherit ITEM;
int cure_ob(string);
void create() {
    set_name("蛇藥", ({"she yao", "yao"}));
    set("unit", "包");
    set("value", 200);
    set("no_sell", 1);
    setup();
}


int cure_ob(object me) {
    message_vision("$N吃下一包" + name() + "。\n", me);
    if ((int)me->query_condition("snake_poison") > 7) {
        me->apply_condition("snake_poison", (int)me->query_condition("snake_poison") - 5);
    }

    destruct(this_object());
    return 1;
}
