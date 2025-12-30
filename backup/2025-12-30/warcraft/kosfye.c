// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;34m伍福緣[2;37;0m[2;37;0m", ({"kosfyepet"}));        
        set("gender", "男性");                
        set("long", "美麗中國夢[2;37;0m
它是福緣伍的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "kosfye");
        set("owner_name", "福緣伍");
        set_temp("owner", "kosfye");
        set_temp("owner_name", "福緣伍");
        ::setup();
}
