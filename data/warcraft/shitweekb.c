// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("異形[2;37;0m[2;37;0m", ({"dna"}));        
        set("gender", "男性");                
        set("long", "逆種[2;37;0m
它是二長的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "shitweekb");
        set("owner_name", "二長");
        set_temp("owner", "shitweekb");
        set_temp("owner_name", "二長");
        ::setup();
}
