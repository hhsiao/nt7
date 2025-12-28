// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("雲淡風輕[2;37;0m[2;37;0m", ({"sleepbag"}));        
        set("gender", "男性");                
        set("long", "如風如雲快跑奔馳的麒麟[2;37;0m
它是馬成的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "matlab");
        set("owner_name", "馬成");
        set_temp("owner", "matlab");
        set_temp("owner_name", "馬成");
        ::setup();
}
