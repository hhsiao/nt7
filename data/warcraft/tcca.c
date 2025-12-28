// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("馬一[2;37;0m[2;37;0m", ({"tccaa"}));        
        set("gender", "男性");                
        set("long", "馬一[2;37;0m
它是偷一的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "tcca");
        set("owner_name", "偷一");
        set_temp("owner", "tcca");
        set_temp("owner_name", "偷一");
        ::setup();
}
