// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("東清龍[2;37;0m[2;37;0m", ({"eastdragon"}));        
        set("gender", "男性");                
        set("long", "這是四勝售的東清龍[2;37;0m
它是天藍神魔的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "jasmine");
        set("owner_name", "天藍神魔");
        set_temp("owner", "jasmine");
        set_temp("owner_name", "天藍神魔");
        ::setup();
}
