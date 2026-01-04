// medicine1.c
// Last Modified by Lonely on May. 29 2001

#include <ansi.h>
inherit ITEM;

void create() {
    set_name(HIY"黃帝內經"NOR, ({ "huangdi neijing", "neijing", "jing"}));
    set_weight(10);
    set("unit", "本");
    set("long", "這是據傳上古時代軒轅黃帝傳世的醫書。\n");
    set("value", 1500);
    set("material", "paper");
    set("skill", ([
        "name": "medicine",
        "exp_required": 100,
        "jing_cost": 10,
        "difficulty": 20,
        "min_skill": 0,
        "max_skill": 30
        ]) );
}
