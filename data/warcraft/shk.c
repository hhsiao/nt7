// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("龍捲風[2;37;0m[2;37;0m", ({"waa"}));        
        set("gender", "男性");                
        set("long", "龍捲風[2;37;0m
它是娃媧媧的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "shk");
        set("owner_name", "娃媧媧");
        set_temp("owner", "shk");
        set_temp("owner_name", "娃媧媧");
        ::setup();
}
