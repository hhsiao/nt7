// wudu-ling.c 五毒令
// Modified by Venus Nov.1997
#include <ansi.h>
inherit ITEM;
void create() {
    set_name(HIB"五毒令"NOR, ({"wudu ling", "ling"}));
    set_weight(500);
    set("unit", "面");
    set("long", "這一塊五毒令，憑此牌弟子可要毒蟲。\n");
    set("value", 0);
    set("material", "steel");
}
