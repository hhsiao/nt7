// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("啾啾擠擠[2;37;0m[2;37;0m", ({"myzuoqi"}));        
        set("gender", "女性");                
        set("long", "啾啾擠擠[2;37;0m
它是沐藝的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "wwoodyi");
        set("owner_name", "沐藝");
        set_temp("owner", "wwoodyi");
        set_temp("owner_name", "沐藝");
        ::setup();
}
