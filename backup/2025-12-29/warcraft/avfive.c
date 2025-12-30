// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("麒麟[2;37;0m[2;37;0m", ({"qilin"}));        
        set("gender", "男性");                
        set("long", "麒麟[2;37;0m
它是里美老師的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "avfive");
        set("owner_name", "里美老師");
        set_temp("owner", "avfive");
        set_temp("owner_name", "里美老師");
        ::setup();
}
