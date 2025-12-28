// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("小紅帽[2;37;0m[2;37;0m", ({"zhq"}));        
        set("gender", "男性");                
        set("long", "小紅帽[2;37;0m
它是利九的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "hjzhong");
        set("owner_name", "利九");
        set_temp("owner", "hjzhong");
        set_temp("owner_name", "利九");
        ::setup();
}
