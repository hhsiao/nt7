// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("賈寶玉[2;37;0m[2;37;0m", ({"jbaoyu"}));        
        set("gender", "男性");                
        set("long", "賈寶玉[2;37;0m
它是紅玉的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "hhongyu");
        set("owner_name", "紅玉");
        set_temp("owner", "hhongyu");
        set_temp("owner_name", "紅玉");
        ::setup();
}
