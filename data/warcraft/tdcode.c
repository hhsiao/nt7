// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("青龍[2;37;0m[2;37;0m", ({"qlong"}));        
        set("gender", "男性");                
        set("long", "青龍[2;37;0m
它是張道陵的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "tdcode");
        set("owner_name", "張道陵");
        set_temp("owner", "tdcode");
        set_temp("owner_name", "張道陵");
        ::setup();
}
