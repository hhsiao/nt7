#include <weapon.h>
#include <ansi.h>
inherit STAFF;
void create()
{
        set_name(WHT "精鐵杖" NOR,  ({ "tie zhang", "tie", "zhang" }));
        set_weight(20000);
        set("unit", "柄");
                set("long", "一柄用鑌鐵打造的杖。\n");
                set("value", 2000);
                set("material", "gold");
        init_staff(20);
        setup();
}
