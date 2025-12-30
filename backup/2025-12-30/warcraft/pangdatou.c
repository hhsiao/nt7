// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("瘦成閃電[2;37;0m[2;37;0m", ({"bigwave"}));        
        set("gender", "男性");                
        set("long", "一頭速度很快的東東[2;37;0m
它是胖大頭的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "pangdatou");
        set("owner_name", "胖大頭");
        set_temp("owner", "pangdatou");
        set_temp("owner_name", "胖大頭");
        ::setup();
}
