// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;34m叄學[2;37;0m[2;37;0m", ({"kosxxcpet"}));        
        set("gender", "男性");                
        set("long", "美麗中國夢[2;37;0m
它是學叄的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "kosxxc");
        set("owner_name", "學叄");
        set_temp("owner", "kosxxc");
        set_temp("owner_name", "學叄");
        ::setup();
}
