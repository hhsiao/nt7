// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("龍[2;37;0m[2;37;0m", ({"dragon_d"}));        
        set("gender", "女性");                
        set("long", "龍[2;37;0m
它是龍王四的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "dragond");
        set("owner_name", "龍王四");
        set_temp("owner", "dragond");
        set_temp("owner_name", "龍王四");
        ::setup();
}
