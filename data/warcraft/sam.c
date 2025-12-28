// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("飛絮[2;37;0m[2;37;0m", ({"sams"}));        
        set("gender", "男性");                
        set("long", "飛絮飄飄[2;37;0m
它是楓龍的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "sam");
        set("owner_name", "楓龍");
        set_temp("owner", "sam");
        set_temp("owner_name", "楓龍");
        ::setup();
}
