// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("薄薄[2;37;0m[2;37;0m", ({"axx"}));        
        set("gender", "男性");                
        set("long", "asdasdas[2;37;0m
它是厚厚的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "master");
        set("owner_name", "厚厚");
        set_temp("owner", "master");
        set_temp("owner_name", "厚厚");
        ::setup();
}
