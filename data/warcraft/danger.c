// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;33m雙龍探珠[2;37;0m[2;37;0m", ({"nonger"}));        
        set("gender", "男性");                
        set("long", "雙龍探珠[2;37;0m
它是二分半的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "danger");
        set("owner_name", "二分半");
        set_temp("owner", "danger");
        set_temp("owner_name", "二分半");
        ::setup();
}
