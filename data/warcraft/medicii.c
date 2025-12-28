// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;32m鋼鐵裝甲[2;37;0m[2;37;0m", ({"tank"}));        
        set("gender", "男性");                
        set("long", "鋼鐵裝甲[2;37;0m
它是製藥二號的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "medicii");
        set("owner_name", "製藥二號");
        set_temp("owner", "medicii");
        set_temp("owner_name", "製藥二號");
        ::setup();
}
