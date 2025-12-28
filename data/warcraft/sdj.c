// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("終生之盟[2;37;0m[2;37;0m", ({"sdjs"}));        
        set("gender", "男性");                
        set("long", "終生之盟[2;37;0m
它是少東家的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "sdj");
        set("owner_name", "少東家");
        set_temp("owner", "sdj");
        set_temp("owner_name", "少東家");
        ::setup();
}
