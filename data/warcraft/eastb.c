// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;31m東方天二[2;37;0m[2;37;0m", ({"eastbb"}));        
        set("gender", "女性");                
        set("long", "$HIR$東方天二[2;37;0m
它是東方二的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "eastb");
        set("owner_name", "東方二");
        set_temp("owner", "eastb");
        set_temp("owner_name", "東方二");
        ::setup();
}
