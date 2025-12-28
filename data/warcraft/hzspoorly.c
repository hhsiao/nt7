// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("結永[2;37;0m[2;37;0m", ({"feih"}));        
        set("gender", "男性");                
        set("long", "結永[2;37;0m
它是海風的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "hzspoorly");
        set("owner_name", "海風");
        set_temp("owner", "hzspoorly");
        set_temp("owner_name", "海風");
        ::setup();
}
