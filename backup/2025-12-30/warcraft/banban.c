// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("氣昂昂[2;37;0m[2;37;0m", ({"qaa"}));        
        set("gender", "男性");                
        set("long", "氣昂昂啊[2;37;0m
它是班班的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "banban");
        set("owner_name", "班班");
        set_temp("owner", "banban");
        set_temp("owner_name", "班班");
        ::setup();
}
