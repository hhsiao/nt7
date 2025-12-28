// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;31m東方天四[2;37;0m[2;37;0m", ({"eastdd"}));        
        set("gender", "女性");                
        set("long", "$HIR$東方天四[2;37;0m
它是東方四的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "eastd");
        set("owner_name", "東方四");
        set_temp("owner", "eastd");
        set_temp("owner_name", "東方四");
        ::setup();
}
