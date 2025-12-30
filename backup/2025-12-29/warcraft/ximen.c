// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("睡袋[2;37;0m[2;37;0m", ({"sleepbag"}));        
        set("gender", "男性");                
        set("long", "睡袋[2;37;0m
它是西門官人的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "ximen");
        set("owner_name", "西門官人");
        set_temp("owner", "ximen");
        set_temp("owner_name", "西門官人");
        ::setup();
}
