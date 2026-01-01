// jinlun.c 金輪
// Last Modified by Lonely on Sep. 7 2001

#include <ansi.h>;
#include <weapon.h>;
inherit HAMMER;
inherit F_UNIQUE;

void create()
{
        set_name( HIY "金輪" NOR,({ "jin lun" ,"lun" ,"jinlun" }));
        set_weight(100000);
        set("unit", "把");
                set("long",HIY"這是一柄金光閃閃的法輪。\n"NOR);
                set("value", 10000);
                set("material", "gold");
                set("wield_msg", "$N「唰」的一聲抽出一柄$n握在手中。\n");
                set("unwield_msg","$N將手中的$n放回腰間。\n");
        init_hammer(150);
        setup();
}
