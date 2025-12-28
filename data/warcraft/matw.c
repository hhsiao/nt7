// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;34m叄黃[2;37;0m[2;37;0m", ({"matwpet"}));        
        set("gender", "男性");                
        set("long", "美麗中國夢[2;37;0m
它是黃叄的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "matw");
        set("owner_name", "黃叄");
        set_temp("owner", "matw");
        set_temp("owner_name", "黃叄");
        ::setup();
}
