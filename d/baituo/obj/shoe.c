#include <ansi.h>
#include <armor.h>
inherit ITEM;

void create()
{
        set_name("繡花鞋", ({ "xiuhua xie", "xiuhua", "xie", "shoe" }));
        set_weight(300);
        set("unit", "只");
                set("long", HIM "這是一隻漂亮的繡花鞋。\n" NOR);
                set("value", 50);
                set("material", "cloth");
                set("female_only", 1);
                set("armor_prop/armor", 3);
}
