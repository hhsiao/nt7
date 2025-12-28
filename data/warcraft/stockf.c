// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("青龍[2;37;0m[2;37;0m", ({"qinglong"}));        
        set("gender", "男性");                
        set("long", "青龍[2;37;0m
它是庫存己的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "stockf");
        set("owner_name", "庫存己");
        set_temp("owner", "stockf");
        set_temp("owner_name", "庫存己");
        ::setup();
}
