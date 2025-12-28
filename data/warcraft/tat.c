// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("空姐[2;37;0m[2;37;0m", ({"along"}));        
        set("gender", "男性");                
        set("long", "彏人[2;37;0m
它是鴻蒙天猴的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "tat");
        set("owner_name", "鴻蒙天猴");
        set_temp("owner", "tat");
        set_temp("owner_name", "鴻蒙天猴");
        ::setup();
}
