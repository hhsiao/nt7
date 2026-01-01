
#include <armor.h>
#include <ansi.h>

inherit ARMOR;

void create()
{
        set_name(HIB "黑鐵鎧" NOR, ({ "heitie kai", "heitie", "kai" }) );
        set_weight(30000);
        set("unit", "件");
                set("material", "steel");
                set("value", 800000);
                set("armor_prop/armor", 500);
                set("limit", ([
                        "exp"  :  400000,
                        "str"  :  30,
                ]));
        setup();
}

int query_autoload()
{
        return 1;
}
