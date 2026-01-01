// zaoshahuajin.c

#include <armor.h>
#include <ansi.h>
inherit HEAD;
void create()
{
        set_name("皂紗轉角簇花巾", ({ "zaosha huajin", "head" }) );
        set_weight(100);
        set("unit", "塊");
                set("value",800);
                set("material", "cloth");
                set("armor_prop/armor", 1);
        setup();
}
