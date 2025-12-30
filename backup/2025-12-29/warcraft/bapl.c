// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;32m七七[2;37;0m[2;37;0m", ({"qise"}));        
        set("gender", "女性");                
        set("long", "$HIC$這是一天七色彩龍，精緻小巧，威嚴。[2;37;0m
它是色不亦空的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "bapl");
        set("owner_name", "色不亦空");
        set_temp("owner", "bapl");
        set_temp("owner_name", "色不亦空");
        ::setup();
}
