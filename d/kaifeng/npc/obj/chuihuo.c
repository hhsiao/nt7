#include <weapon.h>
inherit STAFF;

void create() {
    set_name("吹火管", ({"chui huoguan", "guan"}));
    set_weight(1000);
    set("unit", "根");
    set("value", 10);
    set("long", "在一端吹氣,使灶火旺盛的竹管.\n");
    set("material", "wood");
    set("wield_msg", "$N「呼」地一聲抽出一把$n握在手中。\n");
    init_staff(5);
    setup();
}
