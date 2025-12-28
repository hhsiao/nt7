// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("麒麟[2;37;0m[2;37;0m", ({"mylong"}));        
        set("gender", "男性");                
        set("long", "麒麟[2;37;0m
它是笑術的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "code");
        set("owner_name", "笑術");
        set_temp("owner", "code");
        set_temp("owner_name", "笑術");
        ::setup();
}
