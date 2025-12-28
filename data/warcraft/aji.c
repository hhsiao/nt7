// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("雞雞[2;37;0m[2;37;0m", ({"jiji"}));        
        set("gender", "男性");                
        set("long", "雞雞[2;37;0m
它是阿己的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "aji");
        set("owner_name", "阿己");
        set_temp("owner", "aji");
        set_temp("owner_name", "阿己");
        ::setup();
}
