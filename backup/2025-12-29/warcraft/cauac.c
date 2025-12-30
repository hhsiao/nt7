// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("獸獸[2;37;0m[2;37;0m", ({"sshou"}));        
        set("gender", "男性");                
        set("long", "獸獸[2;37;0m
它是古越龍山的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "cauac");
        set("owner_name", "古越龍山");
        set_temp("owner", "cauac");
        set_temp("owner_name", "古越龍山");
        ::setup();
}
