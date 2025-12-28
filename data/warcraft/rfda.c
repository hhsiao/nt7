// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("麒麟[2;37;0m[2;37;0m", ({"srfda"}));        
        set("gender", "男性");                
        set("long", "AAAA[2;37;0m
它是冷風的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "rfda");
        set("owner_name", "冷風");
        set_temp("owner", "rfda");
        set_temp("owner_name", "冷風");
        ::setup();
}
