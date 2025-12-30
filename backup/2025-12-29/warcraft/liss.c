// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;35m師師[2;37;0m[2;37;0m", ({"lisss"}));        
        set("gender", "男性");                
        set("long", "呵呵[2;37;0m
它是李師師的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "liss");
        set("owner_name", "李師師");
        set_temp("owner", "liss");
        set_temp("owner_name", "李師師");
        ::setup();
}
