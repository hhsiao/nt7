// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("青龍[2;37;0m[2;37;0m", ({"qinglong"}));        
        set("gender", "男性");                
        set("long", "青龍[2;37;0m
它是庫存辛的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "stockh");
        set("owner_name", "庫存辛");
        set_temp("owner", "stockh");
        set_temp("owner_name", "庫存辛");
        ::setup();
}
