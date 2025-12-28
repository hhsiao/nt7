// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;31m血麒麟[2;37;0m[2;37;0m", ({"sleepbag"}));        
        set("gender", "男性");                
        set("long", "這是來自西藏的純種藏獒。[2;37;0m
它是天機老人的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "tianji");
        set("owner_name", "天機老人");
        set_temp("owner", "tianji");
        set_temp("owner_name", "天機老人");
        ::setup();
}
