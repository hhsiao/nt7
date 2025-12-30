// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("地圖精[2;37;0m[2;37;0m", ({"maphere"}));        
        set("gender", "男性");                
        set("long", "qqew[2;37;0m
它是菠羅的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "orgb");
        set("owner_name", "菠羅");
        set_temp("owner", "orgb");
        set_temp("owner_name", "菠羅");
        ::setup();
}
