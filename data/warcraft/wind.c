// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[5m[1;37m風[2;37;0m[1;31m馳[1;33m電[1;35m掣[2;37;0m[2;37;0m", ({"windy"}));        
        set("gender", "男性");                
        set("long", "風馳電掣[2;37;0m
它是風蕭蕭的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "wind");
        set("owner_name", "風蕭蕭");
        set_temp("owner", "wind");
        set_temp("owner_name", "風蕭蕭");
        ::setup();
}
