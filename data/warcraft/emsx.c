// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("麒麟[2;37;0m[2;37;0m", ({"qilin"}));        
        set("gender", "女性");                
        set("long", "麒麟[2;37;0m
它是羅麗控的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "emsx");
        set("owner_name", "羅麗控");
        set_temp("owner", "emsx");
        set_temp("owner_name", "羅麗控");
        ::setup();
}
