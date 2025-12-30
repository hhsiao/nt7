// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("風之龍[2;37;0m[2;37;0m", ({"lbin"}));        
        set("gender", "男性");                
        set("long", "這是青龍[2;37;0m
它是風知雪的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "lbinn");
        set("owner_name", "風知雪");
        set_temp("owner", "lbinn");
        set_temp("owner_name", "風知雪");
        ::setup();
}
