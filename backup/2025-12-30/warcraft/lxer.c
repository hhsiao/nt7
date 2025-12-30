// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("高潮腎寒[2;37;0m[2;37;0m", ({"mylxer"}));        
        set("gender", "女性");                
        set("long", "高潮腎寒[2;37;0m
它是風林火山的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "lxer");
        set("owner_name", "風林火山");
        set_temp("owner", "lxer");
        set_temp("owner_name", "風林火山");
        ::setup();
}
