#include <ansi.h>
#include <weapon.h>

inherit BLADE;

void create() {
    set_name(CYN "厚背鷹刀" NOR, ({ "ying dao", "ying", "blade", "dao" }) );
    set_weight(4000);
    set("unit", "柄");
    set("value", 340000);
    set("material", "steel");
    init_blade(65);
    setup();
}
