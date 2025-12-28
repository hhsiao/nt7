// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("青龍[2;37;0m[2;37;0m", ({"qinlong"}));        
        set("gender", "男性");                
        set("long", "  [2;37;0m
它是錢打二的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "daqianb");
        set("owner_name", "錢打二");
        set_temp("owner", "daqianb");
        set_temp("owner_name", "錢打二");
        ::setup();
}
