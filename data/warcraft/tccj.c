// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("馬十[2;37;0m[2;37;0m", ({"tccha"}));        
        set("gender", "男性");                
        set("long", "馬十[2;37;0m
它是偷十的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "tccj");
        set("owner_name", "偷十");
        set_temp("owner", "tccj");
        set_temp("owner_name", "偷十");
        ::setup();
}
