// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("麒麟[2;37;0m[2;37;0m", ({"yaosss"}));        
        set("gender", "男性");                
        set("long", "麒麟[2;37;0m
它是藥搜索的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "yaoss");
        set("owner_name", "藥搜索");
        set_temp("owner", "yaoss");
        set_temp("owner_name", "藥搜索");
        ::setup();
}
