// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("龍[2;37;0m[2;37;0m", ({"long"}));        
        set("gender", "男性");                
        set("long", "龍[2;37;0m
它是馬如龍的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "simmer");
        set("owner_name", "馬如龍");
        set_temp("owner", "simmer");
        set_temp("owner_name", "馬如龍");
        ::setup();
}
