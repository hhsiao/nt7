// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("阿嬌[2;37;0m[2;37;0m", ({"bozi"}));        
        set("gender", "男性");                
        set("long", "阿嬌[2;37;0m
它是陰功的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "spedmh");
        set("owner_name", "陰功");
        set_temp("owner", "spedmh");
        set_temp("owner_name", "陰功");
        ::setup();
}
