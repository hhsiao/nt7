// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("飛龍在天[2;37;0m[2;37;0m", ({"feilong"}));        
        set("gender", "男性");                
        set("long", "一隻青龍[2;37;0m
它是風雪飄飛的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "fengbo");
        set("owner_name", "風雪飄飛");
        set_temp("owner", "fengbo");
        set_temp("owner_name", "風雪飄飛");
        ::setup();
}
