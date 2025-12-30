// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("青龍[2;37;0m[2;37;0m", ({"mjt"}));        
        set("gender", "男性");                
        set("long", "青龍一隻[2;37;0m
它是傲天的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "mjtmjt");
        set("owner_name", "傲天");
        set_temp("owner", "mjtmjt");
        set_temp("owner_name", "傲天");
        ::setup();
}
