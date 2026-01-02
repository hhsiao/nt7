#include <ansi.h>
#include <weapon.h>

inherit BLADE;

void create() {
    set_name(HIB "青龍牙" NOR, ({ "qinglong ya", "qinglong", "ya", "blade", "dao" }) );
    set_weight(4000);
    set("unit", "柄");
    set("value", 580000);
    set("material", "steel");
    init_blade(70);
    setup();
}
