// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("飛[2;37;0m[2;37;0m", ({"gogoto"}));        
        set("gender", "女性");                
        set("long", "無[2;37;0m
它是雲一心的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "vovo");
        set("owner_name", "雲一心");
        set_temp("owner", "vovo");
        set_temp("owner_name", "雲一心");
        ::setup();
}
