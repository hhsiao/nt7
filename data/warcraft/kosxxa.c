// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;34m壹學[2;37;0m[2;37;0m", ({"kosxxapet"}));        
        set("gender", "男性");                
        set("long", "美麗中國夢[2;37;0m
它是學壹的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "kosxxa");
        set("owner_name", "學壹");
        set_temp("owner", "kosxxa");
        set_temp("owner_name", "學壹");
        ::setup();
}
