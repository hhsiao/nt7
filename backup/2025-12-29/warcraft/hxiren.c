// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("賈寶玉[2;37;0m[2;37;0m", ({"jbaoyu"}));        
        set("gender", "男性");                
        set("long", "賈寶玉[2;37;0m
它是芳官的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "hxiren");
        set("owner_name", "芳官");
        set_temp("owner", "hxiren");
        set_temp("owner_name", "芳官");
        ::setup();
}
