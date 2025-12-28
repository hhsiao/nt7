// This program is a part of NITAN MudLIB 
// redl 2012/11/1 
#include <weapon.h>
#include <ansi.h>

inherit BLADE;


void create()
{
        set_name(HIB "斬魂刀" NOR, ({ "zhanhun dao", "blade", "zhanhun", "dao" }));
        set_weight(1500);
        /*if (clonep())
                set_default_object(__FILE__);
        else*/ {
                set("long", HIR "此刀乃一品堂將軍赫連鐵樹征戰武林所用，刀下亡魂無數。\n" NOR );
                set("unit", "把");
                set("value", 500000);
                set("material", "steel");
                set("wield_msg", "$N抽出一把$n倒提在手，四周空氣頓時快凝結了。\n");
                set("unwield_msg", "$N將手中的$n插回腰間的刀鞘裡。\n");
        }
        
        init_blade(200);
        
        setup();
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        int n;
        if (!playerp(me)) return to_int(damage_bonus * 1.5);
        return damage_bonus;
}



