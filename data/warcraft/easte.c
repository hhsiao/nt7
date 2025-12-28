// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;37m東方天六[2;37;0m[2;37;0m", ({"eastee"}));        
        set("gender", "女性");                
        set("long", "$HIW$東方天六[2;37;0m
它是東方五的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "easte");
        set("owner_name", "東方五");
        set_temp("owner", "easte");
        set_temp("owner_name", "東方五");
        ::setup();
}
