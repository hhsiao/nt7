// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("青龍[2;37;0m[2;37;0m", ({"nevalooy"}));        
        set("gender", "男性");                
        set("long", "青龍[2;37;0m
它是葉凡塵的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "neval");
        set("owner_name", "葉凡塵");
        set_temp("owner", "neval");
        set_temp("owner_name", "葉凡塵");
        ::setup();
}
