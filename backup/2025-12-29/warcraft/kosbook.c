// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("美麗中國夢[2;37;0m[2;37;0m", ({"kosbookpet"}));        
        set("gender", "男性");                
        set("long", "hi[2;37;0m
它是書痴的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "kosbook");
        set("owner_name", "書痴");
        set_temp("owner", "kosbook");
        set_temp("owner_name", "書痴");
        ::setup();
}
