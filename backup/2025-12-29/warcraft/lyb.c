// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("賊王[2;37;0m[2;37;0m", ({"cib"}));        
        set("gender", "男性");                
        set("long", "賊王來了[2;37;0m
它是葡萄二號的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "lyb");
        set("owner_name", "葡萄二號");
        set_temp("owner", "lyb");
        set_temp("owner_name", "葡萄二號");
        ::setup();
}
