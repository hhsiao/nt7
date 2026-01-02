// green-cloth.c 綠色聖衣
#include <armor.h>
#include <ansi.h>
inherit CLOTH;

void create() {
    set_name(GRN"綠色聖衣"NOR, ({ "cloth" }) );
    set_weight(3000);
    set("long", "這是一件繡著紅色火焰的綠色聖衣。\n");
    set("unit", "件");
    set("material", "cloth");
    set("armor_prop/armor", 10);
    setup();
}
