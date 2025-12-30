// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("神仙龍[2;37;0m[2;37;0m", ({"shengou"}));        
        set("gender", "男性");                
        set("long", "神仙龍[2;37;0m
它是靜心的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "rita");
        set("owner_name", "靜心");
        set_temp("owner", "rita");
        set_temp("owner_name", "靜心");
        ::setup();
}
