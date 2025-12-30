// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;34m玖學[2;37;0m[2;37;0m", ({"kosxxipet"}));        
        set("gender", "男性");                
        set("long", "美麗中國夢[2;37;0m
它是學玖的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "kosxxi");
        set("owner_name", "學玖");
        set_temp("owner", "kosxxi");
        set_temp("owner_name", "學玖");
        ::setup();
}
