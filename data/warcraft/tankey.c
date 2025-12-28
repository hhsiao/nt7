// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("小雨滴[2;37;0m[2;37;0m", ({"coin"}));        
        set("gender", "男性");                
        set("long", "非常小的[2;37;0m
它是嶽布裙的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "tankey");
        set("owner_name", "嶽布裙");
        set_temp("owner", "tankey");
        set_temp("owner_name", "嶽布裙");
        ::setup();
}
