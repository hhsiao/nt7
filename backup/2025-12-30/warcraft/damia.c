// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("騾子[2;37;0m[2;37;0m", ({"damiaa"}));        
        set("gender", "男性");                
        set("long", "rwer[2;37;0m
它是藥販子一的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "damia");
        set("owner_name", "藥販子一");
        set_temp("owner", "damia");
        set_temp("owner_name", "藥販子一");
        ::setup();
}
