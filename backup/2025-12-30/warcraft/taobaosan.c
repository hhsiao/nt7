// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;33m現金寶[2;37;0m[2;37;0m", ({"coinsan"}));        
        set("gender", "男性");                
        set("long", "現金為王，王道現金！[2;37;0m
它是淘寶小叄的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "taobaosan");
        set("owner_name", "淘寶小叄");
        set_temp("owner", "taobaosan");
        set_temp("owner_name", "淘寶小叄");
        ::setup();
}
