// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("麒麟[2;37;0m[2;37;0m", ({"yaouuu"}));        
        set("gender", "男性");                
        set("long", "麒麟[2;37;0m
它是藥優優的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "yaouu");
        set("owner_name", "藥優優");
        set_temp("owner", "yaouu");
        set_temp("owner_name", "藥優優");
        ::setup();
}
