// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[5m[1;34m標緻[1;37m敞篷[2;37;0m[2;37;0m", ({"baima"}));        
        set("gender", "男性");                
        set("long", "這款標緻敞篷為最新款概念車，車震利器、泡妞必備。[2;37;0m
它是洪金寶的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "starh");
        set("owner_name", "洪金寶");
        set_temp("owner", "starh");
        set_temp("owner_name", "洪金寶");
        ::setup();
}
