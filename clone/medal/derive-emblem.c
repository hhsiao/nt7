#include <armor.h>
#include <ansi.h>

int is_xunzhang() { return 1; }
inherit MEDAL;

void create() {
    set_name(MAG "紫金汲取勳章" NOR, ({ "derive emblem", "emblem" }));
    set_weight(3000);
    set("long", MAG "帶在身上可以提升300點汲取速度的效果。\n" NOR);
    set("unit", "塊");
    set("can_summon", 1);
    set("value", 500000);
    set("material", "gold");
    set("armor_prop/derive_times", 300);
    set("enchase/SN", "jq1");
    set("auto_load", 1);
    setup();
}
