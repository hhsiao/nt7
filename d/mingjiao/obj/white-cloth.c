// white-cloth.c 白色聖衣
#include <armor.h>
#include <ansi.h>
inherit CLOTH;

void create() {
    set_name(WHT"白色聖衣"NOR, ({ "cloth" }) );
    set_weight(3000);
    set("long", "這是一件繡著紅色火焰的白色聖衣。\n");
    set("unit", "件");
    set("material", "cloth");
    set("armor_prop/armor", 40);
    setup();
}
