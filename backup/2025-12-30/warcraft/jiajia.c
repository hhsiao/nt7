// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[5m[1;31m甲[1;32m龍[2;37;0m[2;37;0m", ({"jialong"}));        
        set("gender", "男性");                
        set("long", "龍[2;37;0m
它是佳家的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "jiajia");
        set("owner_name", "佳家");
        set_temp("owner", "jiajia");
        set_temp("owner_name", "佳家");
        ::setup();
}
