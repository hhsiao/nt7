// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("青龍[2;37;0m[2;37;0m", ({"out"}));        
        set("gender", "女性");                
        set("long", "青龍[2;37;0m
它是靈汆的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "cuan");
        set("owner_name", "靈汆");
        set_temp("owner", "cuan");
        set_temp("owner_name", "靈汆");
        ::setup();
}
