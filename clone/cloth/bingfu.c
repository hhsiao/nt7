// bingfu.c
// Last Modified by Lonely on May. 25 2001

#include <armor.h>
inherit CLOTH;

void create() {
    set_name("兵服", ({"bing fu", "cloth"}));
    set_weight(3000);
    set("long", "一件兵服，前後有銅鏡護心，中繡大唐二字．\n");
    set("material", "cloth");
    set("value", 300);
    set("unit", "件");
    set("armor_prop/armor", 10);
    setup();
}
