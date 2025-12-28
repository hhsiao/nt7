// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("豬豬[2;37;0m[2;37;0m", ({"aaab"}));        
        set("gender", "男性");                
        set("long", "豬豬[2;37;0m
它是散大的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "wdlowekk");
        set("owner_name", "散大");
        set_temp("owner", "wdlowekk");
        set_temp("owner_name", "散大");
        ::setup();
}
