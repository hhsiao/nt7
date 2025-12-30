// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("袋子[2;37;0m[2;37;0m", ({"daizi"}));        
        set("gender", "男性");                
        set("long", "袋子[2;37;0m
它是藥袋的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "yaodai");
        set("owner_name", "藥袋");
        set_temp("owner", "yaodai");
        set_temp("owner_name", "藥袋");
        ::setup();
}
