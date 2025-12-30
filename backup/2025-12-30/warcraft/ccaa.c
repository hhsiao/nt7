// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("界龍[2;37;0m[2;37;0m", ({"wujia"}));        
        set("gender", "男性");                
        set("long", "胖胖痴肥[2;37;0m
它是無界的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "ccaa");
        set("owner_name", "無界");
        set_temp("owner", "ccaa");
        set_temp("owner_name", "無界");
        ::setup();
}
