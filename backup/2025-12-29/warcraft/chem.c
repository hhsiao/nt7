// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("魔幻獸兌換券[2;37;0m[2;37;0m", ({"coem"}));        
        set("gender", "男性");                
        set("long", "魔幻獸兌換券[2;37;0m
它是周額的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "chem");
        set("owner_name", "周額");
        set_temp("owner", "chem");
        set_temp("owner_name", "周額");
        ::setup();
}
