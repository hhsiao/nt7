#include <ansi.h>
#include <weapon.h>

inherit WHIP;

void create() {
    set_name(RED "麒麟鞭" NOR, ({ "qilin bian", "qilin", "bian", "whip" }) );
    set_weight(4000);
    set("unit", "根");
    set("value", 650000);
    set("material", "steel");
    init_whip(70);
    setup();
}
