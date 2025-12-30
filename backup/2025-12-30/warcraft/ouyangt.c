// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("超級麒麟[2;37;0m[2;37;0m", ({"chqilin"}));        
        set("gender", "女性");                
        set("long", "超級麒麟[2;37;0m
它是歐陽婷的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "ouyangt");
        set("owner_name", "歐陽婷");
        set_temp("owner", "ouyangt");
        set_temp("owner_name", "歐陽婷");
        ::setup();
}
