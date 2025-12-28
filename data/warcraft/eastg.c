// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;37m東方天七[2;37;0m[2;37;0m", ({"eastgg"}));        
        set("gender", "女性");                
        set("long", "$HIW$東方天七[2;37;0m
它是東方七的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "eastg");
        set("owner_name", "東方七");
        set_temp("owner", "eastg");
        set_temp("owner_name", "東方七");
        ::setup();
}
