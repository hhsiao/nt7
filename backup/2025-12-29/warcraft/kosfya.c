// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;34m壹福緣[2;37;0m[2;37;0m", ({"kosfyapet"}));        
        set("gender", "男性");                
        set("long", "美麗中國夢[2;37;0m
它是福緣壹的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "kosfya");
        set("owner_name", "福緣壹");
        set_temp("owner", "kosfya");
        set_temp("owner_name", "福緣壹");
        ::setup();
}
