// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("看來是那個[2;37;0m[2;37;0m", ({"cib"}));        
        set("gender", "男性");                
        set("long", "看來是那個[2;37;0m
它是葡萄十號的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "lyj");
        set("owner_name", "葡萄十號");
        set_temp("owner", "lyj");
        set_temp("owner_name", "葡萄十號");
        ::setup();
}
