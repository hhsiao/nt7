#include <ansi.h>
#include <weapon.h>

inherit SWORD;

void create()
{
            set_name(HIW "玉劍" NOR, ({ "yu jian", "yu", "jian", "sword" }));
            set_weight(500);
            set("unit", "柄");
                set("long", HIW "一柄用白玉做成的長劍，相當的精美。\n" NOR);
                set("value", 5000);
                set("material", "jade");
            init_sword(10);
            setup();
}
