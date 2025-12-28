// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;35m暴[5m[1;36m風[2;37;0m[1;31m狂[5m[1;36m雨[2;37;0m[2;37;0m[2;37;0m", ({"windrain"}));        
        set("gender", "男性");                
        set("long", "狂風暴雨！[2;37;0m
它是風雨飄零的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "evilwind");
        set("owner_name", "風雨飄零");
        set_temp("owner", "evilwind");
        set_temp("owner_name", "風雨飄零");
        ::setup();
}
