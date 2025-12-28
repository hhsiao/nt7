// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;34m俠遊[2;37;0m[2;37;0m", ({"matzpet"}));        
        set("gender", "男性");                
        set("long", "美麗中國夢[2;37;0m
它是遊俠的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "matz");
        set("owner_name", "遊俠");
        set_temp("owner", "matz");
        set_temp("owner_name", "遊俠");
        ::setup();
}
