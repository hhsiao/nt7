// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("紫電[2;37;0m[2;37;0m", ({"zidian"}));        
        set("gender", "男性");                
        set("long", "獨一無二[2;37;0m
它是典圍的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "dian");
        set("owner_name", "典圍");
        set_temp("owner", "dian");
        set_temp("owner_name", "典圍");
        ::setup();
}
