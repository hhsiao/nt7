// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("寶馬[2;37;0m[2;37;0m", ({"sleepbag"}));        
        set("gender", "男性");                
        set("long", "奔馳開來了[2;37;0m
它是單思的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "sand");
        set("owner_name", "單思");
        set_temp("owner", "sand");
        set_temp("owner_name", "單思");
        ::setup();
}
