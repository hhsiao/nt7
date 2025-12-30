// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("神駒[2;37;0m[2;37;0m", ({"longe"}));        
        set("gender", "男性");                
        set("long", "神駒[2;37;0m
它是東門官人的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "miss");
        set("owner_name", "東門官人");
        set_temp("owner", "miss");
        set_temp("owner_name", "東門官人");
        ::setup();
}
