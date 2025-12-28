// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("失[2;37;0m[2;37;0m", ({"horse"}));        
        set("gender", "男性");                
        set("long", "疵[2;37;0m
它是風參的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "ianke");
        set("owner_name", "風參");
        set_temp("owner", "ianke");
        set_temp("owner_name", "風參");
        ::setup();
}
