// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("雀兒[2;37;0m[2;37;0m", ({"elle"}));        
        set("gender", "男性");                
        set("long", "雄[2;37;0m
它是靈水的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "belle");
        set("owner_name", "靈水");
        set_temp("owner", "belle");
        set_temp("owner_name", "靈水");
        ::setup();
}
