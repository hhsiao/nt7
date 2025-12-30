// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;34m陸福緣[2;37;0m[2;37;0m", ({"kosfyfpet"}));        
        set("gender", "男性");                
        set("long", "美麗中國夢[2;37;0m
它是福緣陸的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "kosfyf");
        set("owner_name", "福緣陸");
        set_temp("owner", "kosfyf");
        set_temp("owner_name", "福緣陸");
        ::setup();
}
