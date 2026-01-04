// longpao.c
// Last Modified by Lonely on May. 25 2001

#include <ansi.h>
#include <armor.h>
inherit CLOTH;

void create() {
    set_name(HIY "蟒龍袍" NOR, ({"manglong pao", "cloth", "pao"}));
    set_weight(2000);
    set("unit", "件");
    set("long", "這是一件華貴無比的蟒龍袍。你不由得想穿上它過過皇帝癮。\n");
    set("value", 15000);
    set("material", "cloth");
    set("armor_prop/armor", 15);
    setup();
}
