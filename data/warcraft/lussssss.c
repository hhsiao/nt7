// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("無敵神獸[2;37;0m[2;37;0m", ({"ljs"}));        
        set("gender", "男性");                
        set("long", "混沌時期的神獸[2;37;0m
它是了肋骨的魔幻獸。
");
        set("race_type", "玄武");
        set("magic/type", "water");
        set("owner", "lussssss");
        set("owner_name", "了肋骨");
        set_temp("owner", "lussssss");
        set_temp("owner_name", "了肋骨");
        ::setup();
}
