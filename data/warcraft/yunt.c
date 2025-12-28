// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("雲飛龍[2;37;0m[2;37;0m", ({"yflong"}));        
        set("gender", "男性");                
        set("long", "雲天的飛龍[2;37;0m
它是雲天的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "yunt");
        set("owner_name", "雲天");
        set_temp("owner", "yunt");
        set_temp("owner_name", "雲天");
        ::setup();
}
