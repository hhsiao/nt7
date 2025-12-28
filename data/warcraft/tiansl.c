// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("蚯蚓[2;37;0m[2;37;0m", ({"tiansla"}));        
        set("gender", "男性");                
        set("long", "又細又長[2;37;0m
它是天山來的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "tiansl");
        set("owner_name", "天山來");
        set_temp("owner", "tiansl");
        set_temp("owner_name", "天山來");
        ::setup();
}
