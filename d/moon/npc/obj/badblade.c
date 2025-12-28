#include <ansi.h>
#include <weapon.h>
inherit BLADE;
void create()
{
        set_name( YEL "鈍刀" NOR, ({ "badblade" }) );
        set_weight(48000);
        /*if( clonep() )
                set_default_object(__FILE__);
        else*/ {
                set("unit", "把");
                set("long",
                        
"一把鈍刃的破刀。看來毫不起眼，但聽說這把刀曾附有過無上的殺氣。\n"
);
                set("value", 500);
		set("for_bandit",1);
                set("material", "steel");
                set("wield_msg", "$N不聲不響地抽出一把$n握在手中。\n");
                set("unequip_msg", "$N將手中的$n放下。\n");
        }

        init_blade(150);
        setup();

}