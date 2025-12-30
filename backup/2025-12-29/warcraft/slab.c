// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("白虎[2;37;0m[2;37;0m", ({"slablong"}));        
        set("gender", "男性");                
        set("long", "浮雲[2;37;0m
它是神龍的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "slab");
        set("owner_name", "神龍");
        set_temp("owner", "slab");
        set_temp("owner_name", "神龍");
        ::setup();
}
