// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[30m大錢包[2;37;0m[2;37;0m", ({"qianbaob"}));        
        set("gender", "男性");                
        set("long", "$BLK$大錢包[2;37;0m
它是錢少少的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "anb");
        set("owner_name", "錢少少");
        set_temp("owner", "anb");
        set_temp("owner_name", "錢少少");
        ::setup();
}
