// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;32m青龍[2;37;0m[2;37;0m", ({"ala"}));        
        set("gender", "男性");                
        set("long", "青龍[2;37;0m
它是擼啊擼的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "lal");
        set("owner_name", "擼啊擼");
        set_temp("owner", "lal");
        set_temp("owner_name", "擼啊擼");
        ::setup();
}
