// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("雲逐風[2;37;0m[2;37;0m", ({"wincloud"}));        
        set("gender", "男性");                
        set("long", "無[2;37;0m
它是謝古的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "tofu");
        set("owner_name", "謝古");
        set_temp("owner", "tofu");
        set_temp("owner_name", "謝古");
        ::setup();
}
