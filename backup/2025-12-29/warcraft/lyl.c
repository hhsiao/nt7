// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("速度估計回家[2;37;0m[2;37;0m", ({"cib"}));        
        set("gender", "男性");                
        set("long", "速度估計回家[2;37;0m
它是櫻桃二號的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "lyl");
        set("owner_name", "櫻桃二號");
        set_temp("owner", "lyl");
        set_temp("owner_name", "櫻桃二號");
        ::setup();
}
