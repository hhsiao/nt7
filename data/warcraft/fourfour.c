// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("珀金斯[2;37;0m[2;37;0m", ({"toto"}));        
        set("gender", "男性");                
        set("long", "PERKINS[2;37;0m
它是活塞環的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "fourfour");
        set("owner_name", "活塞環");
        set_temp("owner", "fourfour");
        set_temp("owner_name", "活塞環");
        ::setup();
}
