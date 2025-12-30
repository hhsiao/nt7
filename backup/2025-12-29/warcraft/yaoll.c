// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("浪裡狼[2;37;0m[2;37;0m", ({"yaolll"}));        
        set("gender", "男性");                
        set("long", "浪裡狼[2;37;0m
它是藥流量的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "yaoll");
        set("owner_name", "藥流量");
        set_temp("owner", "yaoll");
        set_temp("owner_name", "藥流量");
        ::setup();
}
