// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("小小鳥[2;37;0m[2;37;0m", ({"mybird"}));        
        set("gender", "女性");                
        set("long", "小小鳥[2;37;0m
它是東門吹牛的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "trytry");
        set("owner_name", "東門吹牛");
        set_temp("owner", "trytry");
        set_temp("owner_name", "東門吹牛");
        ::setup();
}
