// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;34m陸研[2;37;0m[2;37;0m", ({"kosyjfpet"}));        
        set("gender", "男性");                
        set("long", "美麗中國夢[2;37;0m
它是研陸的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "kosyjf");
        set("owner_name", "研陸");
        set_temp("owner", "kosyjf");
        set_temp("owner_name", "研陸");
        ::setup();
}
