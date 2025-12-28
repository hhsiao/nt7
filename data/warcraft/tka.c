// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("綿工[2;37;0m[2;37;0m", ({"atk"}));        
        set("gender", "男性");                
        set("long", "綿工[2;37;0m
它是臨兵的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "tka");
        set("owner_name", "臨兵");
        set_temp("owner", "tka");
        set_temp("owner_name", "臨兵");
        ::setup();
}
