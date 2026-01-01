#include <ansi.h>
#include <weapon.h>
inherit BLADE;

void create()
{
        set_name(NOR + HIC "暗月刀" NOR, ({ "anyue dao", "anyue", "dao" }));
        set_weight(100);
        set("unit", "柄");
                set("value", 2000);
                set("material", "steel");
                set("wield_msg", "$N「唰」的一聲抽出一把$n握在手中。\n");
                set("unwield_msg", "$N將手中的$n插回刀鞘。\n");
        init_blade(500);
        setup();
}
