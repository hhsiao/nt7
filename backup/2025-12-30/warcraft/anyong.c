// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("麒麟獸[2;37;0m[2;37;0m", ({"qilinshou"}));        
        set("gender", "男性");                
        set("long", "攻擊坐騎[2;37;0m
它是暗湧的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "anyong");
        set("owner_name", "暗湧");
        set_temp("owner", "anyong");
        set_temp("owner_name", "暗湧");
        ::setup();
}
