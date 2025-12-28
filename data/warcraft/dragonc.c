// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("龍[2;37;0m[2;37;0m", ({"dragon_c"}));        
        set("gender", "男性");                
        set("long", "龍[2;37;0m
它是龍王三的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "dragonc");
        set("owner_name", "龍王三");
        set_temp("owner", "dragonc");
        set_temp("owner_name", "龍王三");
        ::setup();
}
