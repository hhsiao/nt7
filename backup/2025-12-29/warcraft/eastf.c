// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;37m東方天五[2;37;0m[2;37;0m", ({"eastff"}));        
        set("gender", "女性");                
        set("long", "$HIW$東方天五[2;37;0m
它是東方六的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "eastf");
        set("owner_name", "東方六");
        set_temp("owner", "eastf");
        set_temp("owner_name", "東方六");
        ::setup();
}
