// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("龍[2;37;0m[2;37;0m", ({"long"}));        
        set("gender", "男性");                
        set("long", "龍[2;37;0m
它是製衣師傅的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "icloth");
        set("owner_name", "製衣師傅");
        set_temp("owner", "icloth");
        set_temp("owner_name", "製衣師傅");
        ::setup();
}
