// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[5m[31m傅[1;32m紅[1;37m雪[2;37;0m[2;37;0m", ({"eat_liang"}));        
        set("gender", "男性");                
        set("long", "規定[2;37;0m
它是胡十二的魔幻獸。
");
        set("race_type", "玄武");
        set("magic/type", "water");
        set("owner", "hua");
        set("owner_name", "胡十二");
        set_temp("owner", "hua");
        set_temp("owner_name", "胡十二");
        ::setup();
}
