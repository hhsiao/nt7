// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("小毛[2;37;0m[2;37;0m", ({"maburahoo"}));        
        set("gender", "男性");                
        set("long", "123[2;37;0m
它是莫問的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "maburaho");
        set("owner_name", "莫問");
        set_temp("owner", "maburaho");
        set_temp("owner_name", "莫問");
        ::setup();
}
