// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("青龍[2;37;0m[2;37;0m", ({"fgh"}));        
        set("gender", "女性");                
        set("long", "屌絲[2;37;0m
它是破甜的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "pot");
        set("owner_name", "破甜");
        set_temp("owner", "pot");
        set_temp("owner_name", "破甜");
        ::setup();
}
