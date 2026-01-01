#include <weapon.h>
inherit STAFF;

void create()
{
        set_name("招魂幡", ({ "zhaohun fan", "zhaohun", "fan" }));
        set_weight(2000);
        set("unit", "面");
                set("long", "這是一面精鐵打鑄的招魂幡。\n");
                set("value", 800);
                set("rigidity", 100);
                set("material", "steel");
                set("wield_msg", "$N抽出一面$n握在手中。\n");
                set("unwield_msg", "$N將手中的$n插回腰間。\n");
        init_staff(35);
        setup();
}
