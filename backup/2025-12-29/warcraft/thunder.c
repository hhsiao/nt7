// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[5m[1;33m雷[2;37;0m[1;31m厲[1;36m風[1;32m行[2;37;0m[2;37;0m", ({"lei"}));        
        set("gender", "男性");                
        set("long", "雷厲風行[2;37;0m
它是雷隱隱的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "thunder");
        set("owner_name", "雷隱隱");
        set_temp("owner", "thunder");
        set_temp("owner_name", "雷隱隱");
        ::setup();
}
