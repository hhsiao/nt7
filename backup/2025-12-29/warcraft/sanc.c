// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("寶馬[2;37;0m[2;37;0m", ({"sleepbag"}));        
        set("gender", "男性");                
        set("long", "奔馳開來了[2;37;0m
它是單三的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "sanc");
        set("owner_name", "單三");
        set_temp("owner", "sanc");
        set_temp("owner_name", "單三");
        ::setup();
}
