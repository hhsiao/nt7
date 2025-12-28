// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("龍[2;37;0m[2;37;0m", ({"dragon_f"}));        
        set("gender", "女性");                
        set("long", "龍[2;37;0m
它是龍王六的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "dragonf");
        set("owner_name", "龍王六");
        set_temp("owner", "dragonf");
        set_temp("owner_name", "龍王六");
        ::setup();
}
