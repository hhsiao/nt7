// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;34m貳華[2;37;0m[2;37;0m", ({"matgpet"}));        
        set("gender", "男性");                
        set("long", "美麗中國夢[2;37;0m
它是華貳的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "matg");
        set("owner_name", "華貳");
        set_temp("owner", "matg");
        set_temp("owner_name", "華貳");
        ::setup();
}
