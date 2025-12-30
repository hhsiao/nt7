// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;35m狂[1;36m風[2;37;0m[2;37;0m[2;37;0m", ({"phome"}));        
        set("gender", "男性");                
        set("long", "一陣風[2;37;0m
它是亞夜風的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "loume");
        set("owner_name", "亞夜風");
        set_temp("owner", "loume");
        set_temp("owner_name", "亞夜風");
        ::setup();
}
