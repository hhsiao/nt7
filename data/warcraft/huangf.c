// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("廳在[2;37;0m[2;37;0m", ({"hsdf"}));        
        set("gender", "男性");                
        set("long", "廳在[2;37;0m
它是二頂戴的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "huangf");
        set("owner_name", "二頂戴");
        set_temp("owner", "huangf");
        set_temp("owner_name", "二頂戴");
        ::setup();
}
