// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;34m肆學[2;37;0m[2;37;0m", ({"kosxxdpet"}));        
        set("gender", "男性");                
        set("long", "美麗中國夢[2;37;0m
它是學肆的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "kosxxd");
        set("owner_name", "學肆");
        set_temp("owner", "kosxxd");
        set_temp("owner_name", "學肆");
        ::setup();
}
