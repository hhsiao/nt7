// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;31m火箭[2;37;0m[2;37;0m", ({"feiji"}));        
        set("gender", "男性");                
        set("long", "finish[2;37;0m
它是午夜在線的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "superjla");
        set("owner_name", "午夜在線");
        set_temp("owner", "superjla");
        set_temp("owner_name", "午夜在線");
        ::setup();
}
