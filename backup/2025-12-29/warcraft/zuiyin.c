// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("詩意天城[2;37;0m[2;37;0m", ({"shiyi"}));        
        set("gender", "男性");                
        set("long", "單刀殘軀飲寒風，今朝有酒醉黃龍。[2;37;0m
它是醉飲黃龍的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "zuiyin");
        set("owner_name", "醉飲黃龍");
        set_temp("owner", "zuiyin");
        set_temp("owner_name", "醉飲黃龍");
        ::setup();
}
