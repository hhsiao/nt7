// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("地圖精[2;37;0m[2;37;0m", ({"maphere"}));        
        set("gender", "男性");                
        set("long", "23456[2;37;0m
它是聖女果的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "orgj");
        set("owner_name", "聖女果");
        set_temp("owner", "orgj");
        set_temp("owner_name", "聖女果");
        ::setup();
}
