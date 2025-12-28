// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("又鳥[2;37;0m[2;37;0m", ({"mypet"}));        
        set("gender", "女性");                
        set("long", "又鳥[2;37;0m
它是龐春梅的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "chunmei");
        set("owner_name", "龐春梅");
        set_temp("owner", "chunmei");
        set_temp("owner_name", "龐春梅");
        ::setup();
}
