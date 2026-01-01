// yuanxiang.c 軟香鞋
// Last Modified by Lonely on May. 25 2001

#include <armor.h>
#include <ansi.h>
inherit BOOTS;

void create()
{
        set_name(RED"軟香鞋"NOR, ({"ruanxiang xie", "shoes", "xie"}) );
        set_weight(900);
        set("long", "一雙小巧溫軟的繡花鞋。\n");
                set("material", "cloth");
                set("unit", "雙");
                set("value", 2000);
                set("armor_prop/armor", 1 );
                set("armor_prop/per", 3);
                set("female_only", 1);
        setup();
}
