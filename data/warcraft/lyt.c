// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("黃[2;37;0m[2;37;0m", ({"dragon"}));        
        set("gender", "女性");                
        set("long", "look[2;37;0m
它是老油老的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "lyt");
        set("owner_name", "老油老");
        set_temp("owner", "lyt");
        set_temp("owner_name", "老油老");
        ::setup();
}
