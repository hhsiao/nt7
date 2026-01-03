// Code of ShenZhou
// wsky 4/7/00

#include <ansi.h>
#include <weapon.h>

inherit ITEM;

void create() {
    set_name("毒丹", ({ "du dan", "dan"}));
    set_weight(1000);
    set("unit", "塊");
    set("long", HIR"一塊腥紅如血的丹丸。\n"NOR);
    set("material", "stone");
    setup();
}
