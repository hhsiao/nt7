// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("青月[2;37;0m[2;37;0m", ({"qer"}));        
        set("gender", "女性");                
        set("long", "這是一頭無比美麗優雅的小仙女龍[2;37;0m
它是情若天的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "honwell");
        set("owner_name", "情若天");
        set_temp("owner", "honwell");
        set_temp("owner_name", "情若天");
        ::setup();
}
