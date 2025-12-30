// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("阿嬌[2;37;0m[2;37;0m", ({"bozi"}));        
        set("gender", "男性");                
        set("long", "阿嬌[2;37;0m
它是屈寒山的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "spedma");
        set("owner_name", "屈寒山");
        set_temp("owner", "spedma");
        set_temp("owner_name", "屈寒山");
        ::setup();
}
