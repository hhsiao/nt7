#include <ansi.h>

inherit TESSERA;

void create()
{
        set_name(HIY "上古·太虛" NOR, ({"tai xu", "tai", "xu"}));
        set_weight(50);
        set("long", HIY "一塊金黃色的太虛，擁有無窮變化的魔力，這\n"
                            "便是傳說中的至寶——上古太虛，相傳為上古\n"
                            "時代，黃帝得九天玄女所送南北精鐵煉製而成。\n"
                            "上古神物，已經通靈。\n" NOR);
                set("value", 10000000);
                set("unit", "塊");
                set("can_be_tessera", 1);
                set("magic/type", "metal");
                set("magic/power", 1000);
        set("enchase/SN", 5 + random(5));
        set("enchase/type", "all");
        set("enchase/weapon_prop", ([
                "add_metal" : 3,
                "add_skill" : 30,
                "research_effect" : 3,
                "practice_effect" : 3,
                "derive_effect" : 3,
        ]));
        set("enchase/armor_prop", ([
                "reduce_wood" : 1,
                "research_effect" : 3,
                "practice_effect" : 3,
                "derive_effect" : 3,
        ]));
        setup();
}

int query_autoload() { return 1; }
