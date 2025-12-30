// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("龍[2;37;0m[2;37;0m", ({"dragon_b"}));        
        set("gender", "男性");                
        set("long", "龍[2;37;0m
它是龍王二的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "dragonb");
        set("owner_name", "龍王二");
        set_temp("owner", "dragonb");
        set_temp("owner_name", "龍王二");
        ::setup();
}
