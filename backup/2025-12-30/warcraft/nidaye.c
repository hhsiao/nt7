// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("阿嬌[2;37;0m[2;37;0m", ({"bozi"}));        
        set("gender", "男性");                
        set("long", "阿嬌[2;37;0m
它是兆秋息的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "nidaye");
        set("owner_name", "兆秋息");
        set_temp("owner", "nidaye");
        set_temp("owner_name", "兆秋息");
        ::setup();
}
