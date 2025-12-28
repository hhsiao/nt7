// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("青龍[2;37;0m[2;37;0m", ({"qlong"}));        
        set("gender", "男性");                
        set("long", "傻里傻氣的青龍，估計跑的還挺快的[2;37;0m
它是龍四龍的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "xiaojuan");
        set("owner_name", "龍四龍");
        set_temp("owner", "xiaojuan");
        set_temp("owner_name", "龍四龍");
        ::setup();
}
