// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("風龍[2;37;0m[2;37;0m", ({"fenglong"}));        
        set("gender", "男性");                
        set("long", "風龍[2;37;0m
它是赤練子的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "wudan");
        set("owner_name", "赤練子");
        set_temp("owner", "wudan");
        set_temp("owner_name", "赤練子");
        ::setup();
}
