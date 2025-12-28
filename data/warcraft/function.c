// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("賤人[2;37;0m[2;37;0m", ({"fun"}));        
        set("gender", "女性");                
        set("long", "賤人[2;37;0m
它是賤相的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "function");
        set("owner_name", "賤相");
        set_temp("owner", "function");
        set_temp("owner_name", "賤相");
        ::setup();
}
