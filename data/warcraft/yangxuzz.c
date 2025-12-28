// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("聶小倩[2;37;0m[2;37;0m", ({"zzyangxu"}));        
        set("gender", "男性");                
        set("long", "聶小倩[2;37;0m
它是楊旭的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "yangxuzz");
        set("owner_name", "楊旭");
        set_temp("owner", "yangxuzz");
        set_temp("owner_name", "楊旭");
        ::setup();
}
