#include <ansi.h>
#include <weapon.h>

inherit WHIP;

void create()
{
        set_name(HIW "纏魂絲" NOR, ({ "chanhun si", "si", "chanhun", "whip" }) );
        set_weight(4000);
        set("unit", "根");
                set("value", 230000);
                set("material", "steel");
        init_whip(50);
        setup();
}
