// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("你好[2;37;0m[2;37;0m", ({"qilin"}));        
        set("gender", "男性");                
        set("long", "111122[2;37;0m
它是劉備的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "crazyf");
        set("owner_name", "劉備");
        set_temp("owner", "crazyf");
        set_temp("owner_name", "劉備");
        ::setup();
}
