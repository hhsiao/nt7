// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;34m叄華[2;37;0m[2;37;0m", ({"matspet"}));        
        set("gender", "男性");                
        set("long", "美麗中國夢[2;37;0m
它是華叄的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "mats");
        set("owner_name", "華叄");
        set_temp("owner", "mats");
        set_temp("owner_name", "華叄");
        ::setup();
}
