#include <armor.h>
#include <ansi.h>

int is_xunzhang() { return 1; }
inherit MEDAL;

void create()
{
        set_name(MAG "紫金讀書勳章" NOR, ({ "study emblem", "emblem" }));
        set_weight(3000);
        set("long", MAG "帶在身上可以提升讀書最大次數三百次。\n" NOR);
                set("unit", "塊");
                set("can_summon", 1);
                set("no_sell", 1);
                set("value", 500000);
                set("material", "gold");
                set("armor_prop/study_times", 300);
        set("enchase/SN", "ds1");
        set("auto_load", 1);
        setup();
}
