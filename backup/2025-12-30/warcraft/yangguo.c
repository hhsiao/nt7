// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("天空[2;37;0m[2;37;0m", ({"tian"}));        
        set("gender", "男性");                
        set("long", "藍藍的天空[2;37;0m
它是楊過的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "yangguo");
        set("owner_name", "楊過");
        set_temp("owner", "yangguo");
        set_temp("owner_name", "楊過");
        ::setup();
}
