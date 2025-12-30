// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[5m[1;36m雲[2;37;0m[1;31m起[1;32m龍[1;35m驤[2;37;0m[2;37;0m", ({"cloudy"}));        
        set("gender", "男性");                
        set("long", "雲起龍驤[2;37;0m
它是雲飄飄的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "cloud");
        set("owner_name", "雲飄飄");
        set_temp("owner", "cloud");
        set_temp("owner_name", "雲飄飄");
        ::setup();
}
