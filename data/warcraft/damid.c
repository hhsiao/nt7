// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("騾子[2;37;0m[2;37;0m", ({"damidd"}));        
        set("gender", "男性");                
        set("long", "fdg[2;37;0m
它是藥販子四的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "damid");
        set("owner_name", "藥販子四");
        set_temp("owner", "damid");
        set_temp("owner_name", "藥販子四");
        ::setup();
}
