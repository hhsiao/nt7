#include <weapon.h>
#include <ansi.h>
inherit SWORD;
void create()
{
        set_name( "長劍",  ({ "chang jian", "sword", "jian" }));
        set_weight(10000);
        set("unit", "柄");
                set("long", "一柄普通的長劍。\n");
                set("value", 1000);
                set("material", "gold");
        init_sword(10);
        setup();
}
