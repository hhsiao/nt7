// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("小龍[2;37;0m[2;37;0m", ({"xiaolong"}));        
        set("gender", "男性");                
        set("long", "小龍飛來了[2;37;0m
它是霧隱牛牛的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "bbnn");
        set("owner_name", "霧隱牛牛");
        set_temp("owner", "bbnn");
        set_temp("owner_name", "霧隱牛牛");
        ::setup();
}
