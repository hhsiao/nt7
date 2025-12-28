// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("愛騎[2;37;0m[2;37;0m", ({"ilovelong"}));        
        set("gender", "男性");                
        set("long", "愛騎[2;37;0m
它是呂娜的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "lvna");
        set("owner_name", "呂娜");
        set_temp("owner", "lvna");
        set_temp("owner_name", "呂娜");
        ::setup();
}
