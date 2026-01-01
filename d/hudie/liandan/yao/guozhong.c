#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(NOR"果樹種籽"NOR, ({ "shu zhong"}));
        set_weight(100);
        set("long", "普通的果樹種籽，不知道會結出什麼樣的果實。\n");
                set("unit", "粒");
                set("no_get",1);
                set("no_put",1);
                set("no_give",1);
                set("value",50000);
    setup();
}
