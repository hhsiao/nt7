// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("賊娃子[2;37;0m[2;37;0m", ({"cib"}));        
        set("gender", "男性");                
        set("long", "賊娃子來了[2;37;0m
它是葡萄一號的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "lya");
        set("owner_name", "葡萄一號");
        set_temp("owner", "lya");
        set_temp("owner_name", "葡萄一號");
        ::setup();
}
