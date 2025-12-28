// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("麒麟[2;37;0m[2;37;0m", ({"ccii"}));        
        set("gender", "男性");                
        set("long", "麒麟[2;37;0m
它是學哎的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "cci");
        set("owner_name", "學哎");
        set_temp("owner", "cci");
        set_temp("owner_name", "學哎");
        ::setup();
}
