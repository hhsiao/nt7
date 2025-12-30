// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("情侶[2;37;0m[2;37;0m", ({"lmm"}));        
        set("gender", "男性");                
        set("long", "情侶[2;37;0m
它是恆九的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "zzhg");
        set("owner_name", "恆九");
        set_temp("owner", "zzhg");
        set_temp("owner_name", "恆九");
        ::setup();
}
