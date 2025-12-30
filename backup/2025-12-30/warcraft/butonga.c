// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;31m寶馬柒陸零[2;37;0m[2;37;0m", ({"bmw"}));        
        set("gender", "男性");                
        set("long", "finish[2;37;0m
它是布菇孃的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "butonga");
        set("owner_name", "布菇娘");
        set_temp("owner", "butonga");
        set_temp("owner_name", "布菇娘");
        ::setup();
}
