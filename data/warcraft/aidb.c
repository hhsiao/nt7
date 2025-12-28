// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("青龍[2;37;0m[2;37;0m", ({"idb"}));        
        set("gender", "男性");                
        set("long", "青龍[2;37;0m
它是錢夢的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "aidb");
        set("owner_name", "錢夢");
        set_temp("owner", "aidb");
        set_temp("owner_name", "錢夢");
        ::setup();
}
