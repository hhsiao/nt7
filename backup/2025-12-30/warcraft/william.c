// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("蕭麟[2;37;0m[2;37;0m", ({"will"}));        
        set("gender", "男性");                
        set("long", "威猛雄壯的小馬[2;37;0m
它是蕭易的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "william");
        set("owner_name", "蕭易");
        set_temp("owner", "william");
        set_temp("owner_name", "蕭易");
        ::setup();
}
