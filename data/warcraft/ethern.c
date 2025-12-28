// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("阿薩德[2;37;0m[2;37;0m", ({"hahaha"}));        
        set("gender", "女性");                
        set("long", "阿薩德[2;37;0m
它是以太閃電的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "ethern");
        set("owner_name", "以太閃電");
        set_temp("owner", "ethern");
        set_temp("owner_name", "以太閃電");
        ::setup();
}
