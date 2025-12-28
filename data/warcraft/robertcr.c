// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;36m鬧鬧[2;37;0m[2;37;0m", ({"benben"}));        
        set("gender", "男性");                
        set("long", "鬧鬧[2;37;0m
它是澄東的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "robertcr");
        set("owner_name", "澄東");
        set_temp("owner", "robertcr");
        set_temp("owner_name", "澄東");
        ::setup();
}
