// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("青龍[2;37;0m[2;37;0m", ({"out"}));        
        set("gender", "男性");                
        set("long", "青龍[2;37;0m
它是孔夢的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "sure");
        set("owner_name", "孔夢");
        set_temp("owner", "sure");
        set_temp("owner_name", "孔夢");
        ::setup();
}
