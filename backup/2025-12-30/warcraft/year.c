// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[36m黑月追風[2;37;0m[2;37;0m", ({"deer"}));        
        set("gender", "男性");                
        set("long", "好馬[2;37;0m
它是宇文措的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "year");
        set("owner_name", "宇文措");
        set_temp("owner", "year");
        set_temp("owner_name", "宇文措");
        ::setup();
}
