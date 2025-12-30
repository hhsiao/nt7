// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("驢[2;37;0m[2;37;0m", ({"mytongzi"}));        
        set("gender", "男性");                
        set("long", "驢[2;37;0m
它是藥師的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "yaoshi");
        set("owner_name", "藥師");
        set_temp("owner", "yaoshi");
        set_temp("owner_name", "藥師");
        ::setup();
}
