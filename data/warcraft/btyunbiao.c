// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("麒麟[2;37;0m[2;37;0m", ({"qiling"}));        
        set("gender", "女性");                
        set("long", "麒麟[2;37;0m
它是運鏢乙的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "btyunbiao");
        set("owner_name", "運鏢乙");
        set_temp("owner", "btyunbiao");
        set_temp("owner_name", "運鏢乙");
        ::setup();
}
