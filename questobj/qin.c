// qin.c
#include <weapon.h>
#include <ansi.h>
inherit SWORD;
void create()
{
        set_name(HIW"白玉瑤琴"NOR, ({ "yao qin", "qin"}));
        set("taskobj", 1);
        set_weight(6000);
        set("unit", "具");
                set("long", "這是一具用白玉做成的瑤琴。\n");
                set("value", 0);
                set("material", "steel");
                set("wield_msg", "$N從背後將$n拿在手中。\n");
                set("unwield_msg", "$N將手中的$n放回背後。\n");
        setup();
}
