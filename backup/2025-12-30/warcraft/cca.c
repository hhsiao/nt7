// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("麒麟[2;37;0m[2;37;0m", ({"ccaa"}));        
        set("gender", "男性");                
        set("long", "麒麟[2;37;0m
它是學啊的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "cca");
        set("owner_name", "學啊");
        set_temp("owner", "cca");
        set_temp("owner_name", "學啊");
        ::setup();
}
