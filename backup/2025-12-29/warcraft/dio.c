// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("雨琪[2;37;0m[2;37;0m", ({"yuqi"}));        
        set("gender", "女性");                
        set("long", "help nick[2;37;0m
它是雷禪的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "dio");
        set("owner_name", "雷禪");
        set_temp("owner", "dio");
        set_temp("owner_name", "雷禪");
        ::setup();
}
