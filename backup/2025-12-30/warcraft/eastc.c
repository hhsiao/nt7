// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;31m東方天三[2;37;0m[2;37;0m", ({"eastcc"}));        
        set("gender", "女性");                
        set("long", "$HIR$東方天三[2;37;0m
它是東方三的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "eastc");
        set("owner_name", "東方三");
        set_temp("owner", "eastc");
        set_temp("owner_name", "東方三");
        ::setup();
}
