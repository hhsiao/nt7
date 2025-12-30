// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("小馬[2;37;0m[2;37;0m", ({"flya"}));        
        set("gender", "男性");                
        set("long", "finish[2;37;0m
它是口袋的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "xgha");
        set("owner_name", "口袋");
        set_temp("owner", "xgha");
        set_temp("owner_name", "口袋");
        ::setup();
}
