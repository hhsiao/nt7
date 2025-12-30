// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;34m叄雪[2;37;0m[2;37;0m", ({"matqpet"}));        
        set("gender", "男性");                
        set("long", "美麗中國夢[2;37;0m
它是雪叄的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "matq");
        set("owner_name", "雪叄");
        set_temp("owner", "matq");
        set_temp("owner_name", "雪叄");
        ::setup();
}
