// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("安琪[2;37;0m[2;37;0m", ({"angie"}));        
        set("gender", "男性");                
        set("long", "快樂的小安琪[2;37;0m
它是獨孤惜花的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "iloveangie");
        set("owner_name", "獨孤惜花");
        set_temp("owner", "iloveangie");
        set_temp("owner_name", "獨孤惜花");
        ::setup();
}
