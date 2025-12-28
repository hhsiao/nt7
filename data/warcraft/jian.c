// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;31m劍劍[2;37;0m[2;37;0m", ({"jianjian"}));        
        set("gender", "男性");                
        set("long", "$HIR$劍劍[2;37;0m
它是魔劍的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "jian");
        set("owner_name", "魔劍");
        set_temp("owner", "jian");
        set_temp("owner_name", "魔劍");
        ::setup();
}
