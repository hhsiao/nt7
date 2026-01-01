#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
        set_name(HIY "八卦兌澤衣" NOR, ({ "duize yi", "duize", "yi" }));
        set_weight(100);
        set("long", HIY"炎黃風雨十年紀念套裝之：八卦兌澤衣\n" NOR);
                set("unit", "件");
                set("value", 100);
                set("armor_prop/armor", 1000);
                set("armor_prop/T_bagua", 1); // 套裝計數標誌
        setup();
}

int query_autoload()
{
        return 1;
}
