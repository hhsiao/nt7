// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("青龍[2;37;0m[2;37;0m", ({"qing"}));        
        set("gender", "男性");                
        set("long", "威武[2;37;0m
它是渡青的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "thyy");
        set("owner_name", "渡青");
        set_temp("owner", "thyy");
        set_temp("owner_name", "渡青");
        ::setup();
}
