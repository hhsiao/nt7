// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;32m鋼鐵裝甲[2;37;0m[2;37;0m", ({"tank"}));        
        set("gender", "男性");                
        set("long", "鋼鐵裝甲[2;37;0m
它是武當製藥的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "medic");
        set("owner_name", "武當製藥");
        set_temp("owner", "medic");
        set_temp("owner_name", "武當製藥");
        ::setup();
}
