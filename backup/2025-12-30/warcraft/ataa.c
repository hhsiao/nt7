// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("麒麟[2;37;0m[2;37;0m", ({"ataaa"}));        
        set("gender", "女性");                
        set("long", "麒麟[2;37;0m
它是歐陽億的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "ataa");
        set("owner_name", "歐陽億");
        set_temp("owner", "ataa");
        set_temp("owner_name", "歐陽億");
        ::setup();
}
