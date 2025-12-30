// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;33m蓮花寶座[2;37;0m[2;37;0m", ({"myma"}));        
        set("gender", "男性");                
        set("long", "一個金黃色的蓮花寶座[2;37;0m
它是木機的魔幻獸。
");
        set("race_type", "玄武");
        set("magic/type", "water");
        set("owner", "muji");
        set("owner_name", "木機");
        set_temp("owner", "muji");
        set_temp("owner_name", "木機");
        ::setup();
}
