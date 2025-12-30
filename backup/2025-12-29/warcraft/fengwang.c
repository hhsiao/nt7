// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("碧水劍[2;37;0m[2;37;0m", ({"feilong"}));        
        set("gender", "男性");                
        set("long", "青龍[2;37;0m
它是糊大巴的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "fengwang");
        set("owner_name", "糊大巴");
        set_temp("owner", "fengwang");
        set_temp("owner_name", "糊大巴");
        ::setup();
}
