// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("寶馬[2;37;0m[2;37;0m", ({"vik"}));        
        set("gender", "男性");                
        set("long", "。。。。。。[2;37;0m
它是司馬乘風的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "viki");
        set("owner_name", "司馬乘風");
        set_temp("owner", "viki");
        set_temp("owner_name", "司馬乘風");
        ::setup();
}
