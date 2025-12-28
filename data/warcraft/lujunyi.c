// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;31m麒麟獸[2;37;0m[2;37;0m", ({"yuql"}));        
        set("gender", "男性");                
        set("long", "盧俊義的坐騎[2;37;0m
它是盧俊義的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "lujunyi");
        set("owner_name", "盧俊義");
        set_temp("owner", "lujunyi");
        set_temp("owner_name", "盧俊義");
        ::setup();
}
