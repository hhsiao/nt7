// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;36m風掃落葉[2;37;0m[2;37;0m", ({"haichao"}));        
        set("gender", "男性");                
        set("long", "$HIC$風掃落葉[2;37;0m
它是楚蕭的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "thckr");
        set("owner_name", "楚蕭");
        set_temp("owner", "thckr");
        set_temp("owner_name", "楚蕭");
        ::setup();
}
