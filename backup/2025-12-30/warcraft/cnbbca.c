// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("馬[2;37;0m[2;37;0m", ({"whistle_neverfree"}));        
        set("gender", "女性");                
        set("long", "馬[2;37;0m
它是歐陽偉的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "cnbbca");
        set("owner_name", "歐陽偉");
        set_temp("owner", "cnbbca");
        set_temp("owner_name", "歐陽偉");
        ::setup();
}
