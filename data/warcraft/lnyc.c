// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("三哥麒麟[2;37;0m[2;37;0m", ({"lnycride"}));        
        set("gender", "男性");                
        set("long", "三哥麒麟[2;37;0m
它是龍里三哥的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "lnyc");
        set("owner_name", "龍里三哥");
        set_temp("owner", "lnyc");
        set_temp("owner_name", "龍里三哥");
        ::setup();
}
