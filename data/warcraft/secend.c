// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("睡袋[2;37;0m[2;37;0m", ({"sleepbag"}));        
        set("gender", "男性");                
        set("long", "                [2;37;0m
它是胡說的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "secend");
        set("owner_name", "胡說");
        set_temp("owner", "secend");
        set_temp("owner_name", "胡說");
        ::setup();
}
