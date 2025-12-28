// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("飛貓[2;37;0m[2;37;0m", ({"feitian"}));        
        set("gender", "男性");                
        set("long", "飛貓[2;37;0m
它是烽火連天的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "fenghuo");
        set("owner_name", "烽火連天");
        set_temp("owner", "fenghuo");
        set_temp("owner_name", "烽火連天");
        ::setup();
}
