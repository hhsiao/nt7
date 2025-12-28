// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("寬鬆的風口[2;37;0m[2;37;0m", ({"fih"}));        
        set("gender", "男性");                
        set("long", "寬鬆的風口[2;37;0m
它是葡萄八號的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "yjh");
        set("owner_name", "葡萄八號");
        set_temp("owner", "yjh");
        set_temp("owner_name", "葡萄八號");
        ::setup();
}
