// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;34m壹華[2;37;0m[2;37;0m", ({"matfpet"}));        
        set("gender", "男性");                
        set("long", "美麗中國夢[2;37;0m
它是華壹的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "matf");
        set("owner_name", "華壹");
        set_temp("owner", "matf");
        set_temp("owner_name", "華壹");
        ::setup();
}
