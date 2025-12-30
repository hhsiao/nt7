// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;34m肆華[2;37;0m[2;37;0m", ({"mattpet"}));        
        set("gender", "男性");                
        set("long", "美麗中國夢[2;37;0m
它是華肆的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "matt");
        set("owner_name", "華肆");
        set_temp("owner", "matt");
        set_temp("owner_name", "華肆");
        ::setup();
}
