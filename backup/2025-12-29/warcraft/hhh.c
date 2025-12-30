// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("青龍[2;37;0m[2;37;0m", ({"sadas"}));        
        set("gender", "女性");                
        set("long", "dawd1[2;37;0m
它是開心的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "hhh");
        set("owner_name", "開心");
        set_temp("owner", "hhh");
        set_temp("owner_name", "開心");
        ::setup();
}
