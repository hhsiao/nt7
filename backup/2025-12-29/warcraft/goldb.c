// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("錢錢[2;37;0m[2;37;0m", ({"moneyb"}));        
        set("gender", "男性");                
        set("long", "錢錢[2;37;0m
它是錢二的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "goldb");
        set("owner_name", "錢二");
        set_temp("owner", "goldb");
        set_temp("owner_name", "錢二");
        ::setup();
}
