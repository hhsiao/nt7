// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("麒麟[2;37;0m[2;37;0m", ({"qilin"}));        
        set("gender", "男性");                
        set("long", "麒麟[2;37;0m
它是馬汗青的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "sknt");
        set("owner_name", "馬汗青");
        set_temp("owner", "sknt");
        set_temp("owner_name", "馬汗青");
        ::setup();
}
