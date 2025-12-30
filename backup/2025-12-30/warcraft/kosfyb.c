// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;34m貳福緣[2;37;0m[2;37;0m", ({"kosfybpet"}));        
        set("gender", "男性");                
        set("long", "美麗中國夢[2;37;0m
它是福緣貳的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "kosfyb");
        set("owner_name", "福緣貳");
        set_temp("owner", "kosfyb");
        set_temp("owner_name", "福緣貳");
        ::setup();
}
