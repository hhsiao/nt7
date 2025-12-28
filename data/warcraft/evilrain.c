// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[5m[1;36m眼[1;31m花[1;33m繚[1;35m亂[2;37;0m[2;37;0m[2;37;0m", ({"daze"}));        
        set("gender", "女性");                
        set("long", "眼花繚亂！[2;37;0m
它是風雨飄渺的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "evilrain");
        set("owner_name", "風雨飄渺");
        set_temp("owner", "evilrain");
        set_temp("owner_name", "風雨飄渺");
        ::setup();
}
