// medicine3.c
// Last Modified by Lonely on May. 29 2001

#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIY"王叔和脈經"NOR,({"wangshuhe maijing", "maijing", "jing"}));
        set_weight(10);
        set("unit", "本");
                set("long","這是一本王叔和脈。年代久遠，紙質破舊。\n");
                set("value", 1500);
                set("material", "paper");
                set("skill", ([
                        "name":         "medicine",
                        "exp_required": 2000,
                        "jing_cost":    10,
                        "difficulty":   20,
                        "min_skill":    60,
                        "max_skill":    100
                ]) );
}
