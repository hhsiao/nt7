// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[5m[35m太古兇獸[2;37;0m[2;37;0m", ({"clothblong"}));        
        set("gender", "男性");                
        set("long", "萬惡[2;37;0m
它是錦衣衛的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "clothb");
        set("owner_name", "錦衣衛");
        set_temp("owner", "clothb");
        set_temp("owner_name", "錦衣衛");
        ::setup();
}
