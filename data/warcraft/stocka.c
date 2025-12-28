// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("青龍[2;37;0m[2;37;0m", ({"qinlong"}));        
        set("gender", "女性");                
        set("long", "青龍[2;37;0m
它是庫存甲的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "stocka");
        set("owner_name", "庫存甲");
        set_temp("owner", "stocka");
        set_temp("owner_name", "庫存甲");
        ::setup();
}
