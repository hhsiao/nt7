// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("賈寶玉[2;37;0m[2;37;0m", ({"jbaoyu"}));        
        set("gender", "男性");                
        set("long", "賈寶玉[2;37;0m
它是巧姐的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "hqiaojie");
        set("owner_name", "巧姐");
        set_temp("owner", "hqiaojie");
        set_temp("owner_name", "巧姐");
        ::setup();
}
