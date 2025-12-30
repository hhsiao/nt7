// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("輕龍[2;37;0m[2;37;0m", ({"lon"}));        
        set("gender", "男性");                
        set("long", "輕龍[2;37;0m
它是劉浮屠的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "tana");
        set("owner_name", "劉浮屠");
        set_temp("owner", "tana");
        set_temp("owner_name", "劉浮屠");
        ::setup();
}
