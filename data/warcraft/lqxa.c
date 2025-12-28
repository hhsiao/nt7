// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("野獸[2;37;0m[2;37;0m", ({"lqxaa"}));        
        set("gender", "男性");                
        set("long", "醜的要死[2;37;0m
它是東方星的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "lqxa");
        set("owner_name", "東方星");
        set_temp("owner", "lqxa");
        set_temp("owner_name", "東方星");
        ::setup();
}
