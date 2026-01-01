// blake-cloth.c example cloth

#include <ansi.h>

inherit EQUIP;

void create()
{
        set_name( BLK "黑色勁裝" NOR, ({ "cloth" }) );
        set_weight(700);
        set("unit", "件");
                set("value", 500);
                set("material", "cloth");
                set("armor_type", "cloth");
                set("armor_prop/per", 1);
                set("armor_prop/armor", 2);
                set("wear_msg","$N穿上一件$n。\n");
                set("remove_msg","$將$n脫了下來。\n");
}
