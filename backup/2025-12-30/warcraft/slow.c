// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;33m蝸牛[2;37;0m[2;37;0m", ({"mom"}));        
        set("gender", "男性");                
        set("long", "急速蝸牛[2;37;0m
它是從容不破的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "slow");
        set("owner_name", "從容不破");
        set_temp("owner", "slow");
        set_temp("owner_name", "從容不破");
        ::setup();
}
