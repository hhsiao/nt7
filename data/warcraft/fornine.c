// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("天樂龍龍[2;37;0m[2;37;0m", ({"ttlongq"}));        
        set("gender", "男性");                
        set("long", "天樂龍龍[2;37;0m
它是陽九的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "fornine");
        set("owner_name", "陽九");
        set_temp("owner", "fornine");
        set_temp("owner_name", "陽九");
        ::setup();
}
