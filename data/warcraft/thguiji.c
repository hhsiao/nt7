// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("火雞[2;37;0m[2;37;0m", ({"baoma"}));        
        set("gender", "男性");                
        set("long", "火雞[2;37;0m
它是飛龍吹雪的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "thguiji");
        set("owner_name", "飛龍吹雪");
        set_temp("owner", "thguiji");
        set_temp("owner_name", "飛龍吹雪");
        ::setup();
}
