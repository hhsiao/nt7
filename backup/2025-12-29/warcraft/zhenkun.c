// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("雷靈獸[2;37;0m[2;37;0m", ({"leilingshou"}));        
        set("gender", "男性");                
        set("long", "天地雷精所化[2;37;0m
它是林鎮坤的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "zhenkun");
        set("owner_name", "林鎮坤");
        set_temp("owner", "zhenkun");
        set_temp("owner_name", "林鎮坤");
        ::setup();
}
