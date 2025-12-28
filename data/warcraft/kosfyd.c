// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;34m肆福緣[2;37;0m[2;37;0m", ({"kosfydpet"}));        
        set("gender", "男性");                
        set("long", "美麗中國夢[2;37;0m
它是福緣肆的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "kosfyd");
        set("owner_name", "福緣肆");
        set_temp("owner", "kosfyd");
        set_temp("owner_name", "福緣肆");
        ::setup();
}
