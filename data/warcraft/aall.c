// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("阿汪[2;37;0m[2;37;0m", ({"adog"}));        
        set("gender", "男性");                
        set("long", "汪星人[2;37;0m
它是丁當的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "aall");
        set("owner_name", "丁當");
        set_temp("owner", "aall");
        set_temp("owner_name", "丁當");
        ::setup();
}
