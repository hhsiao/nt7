// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[5m[34m沈[1;33m陽[35m技[36m師[2;37;0m[2;37;0m", ({"qinglong"}));        
        set("gender", "男性");                
        set("long", "嘩嘩[2;37;0m
它是劍指中都的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "taoa");
        set("owner_name", "劍指中都");
        set_temp("owner", "taoa");
        set_temp("owner_name", "劍指中都");
        ::setup();
}
