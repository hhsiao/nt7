// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("背學[2;37;0m[2;37;0m", ({"beibei"}));        
        set("gender", "男性");                
        set("long", "背學[2;37;0m
它是血戰到底的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "bei");
        set("owner_name", "血戰到底");
        set_temp("owner", "bei");
        set_temp("owner_name", "血戰到底");
        ::setup();
}
