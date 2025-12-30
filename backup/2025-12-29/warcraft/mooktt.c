// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("遠古青龍[2;37;0m[2;37;0m", ({"qinglong"}));        
        set("gender", "男性");                
        set("long", "一隻遠古青龍。[2;37;0m
它是清小的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "mooktt");
        set("owner_name", "清小");
        set_temp("owner", "mooktt");
        set_temp("owner_name", "清小");
        ::setup();
}
