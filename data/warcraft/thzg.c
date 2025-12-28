// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("獸獸[2;37;0m[2;37;0m", ({"sshou"}));        
        set("gender", "男性");                
        set("long", "獸獸[2;37;0m
它是長工己的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "thzg");
        set("owner_name", "長工己");
        set_temp("owner", "thzg");
        set_temp("owner_name", "長工己");
        ::setup();
}
