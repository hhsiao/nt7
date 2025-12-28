// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("馬八[2;37;0m[2;37;0m", ({"tccfa"}));        
        set("gender", "男性");                
        set("long", "馬八[2;37;0m
它是偷八的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "tcch");
        set("owner_name", "偷八");
        set_temp("owner", "tcch");
        set_temp("owner_name", "偷八");
        ::setup();
}
