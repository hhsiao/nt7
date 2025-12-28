// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;34m霹靂[1;31m赤焰駒[2;37;0m[2;37;0m", ({"baima"}));        
        set("gender", "男性");                
        set("long", "這匹神駒通體赤焰般流動，聲若霹靂、奔如閃電，故名赤焰獸。[2;37;0m
它是龐青雲的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "pang");
        set("owner_name", "龐青雲");
        set_temp("owner", "pang");
        set_temp("owner_name", "龐青雲");
        ::setup();
}
