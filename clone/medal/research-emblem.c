#include <armor.h>
#include <ansi.h>

int is_xunzhang() { return 1; }
inherit MEDAL;

void create()
{
        set_name(MAG "紫金研究勳章" NOR, ({ "research emblem", "emblem" }));
        set_weight(3000);
        /*if (clonep())
                set_default_object(__FILE__);
        else*/
        {
                set("long", MAG "帶在身上可以提升研究最大次數三百次。\n" NOR);
                set("unit", "塊");
                set("can_summon", 1);
                set("value", 500000);
                set("material", "gold");
                set("armor_prop/research_times", 300);
        }
        set("enchase/SN", "yj1");
        set("auto_load", 1);
        setup();
}