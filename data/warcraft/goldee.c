// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("龍[2;37;0m[2;37;0m", ({"goldeee"}));        
        set("gender", "男性");                
        set("long", "龍[2;37;0m
它是金龍的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "goldee");
        set("owner_name", "金龍");
        set_temp("owner", "goldee");
        set_temp("owner_name", "金龍");
        ::setup();
}
