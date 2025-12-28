// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("麒麟[2;37;0m[2;37;0m", ({"dsy"}));        
        set("gender", "男性");                
        set("long", "麒麟[2;37;0m
它是菩丹叄的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "wdpzc");
        set("owner_name", "菩丹叄");
        set_temp("owner", "wdpzc");
        set_temp("owner_name", "菩丹叄");
        ::setup();
}
