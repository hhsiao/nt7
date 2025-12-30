// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("小紅[2;37;0m[2;37;0m", ({"save"}));        
        set("gender", "女性");                
        set("long", "小紅[2;37;0m
它是太極蛋的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "olo");
        set("owner_name", "太極蛋");
        set_temp("owner", "olo");
        set_temp("owner_name", "太極蛋");
        ::setup();
}
