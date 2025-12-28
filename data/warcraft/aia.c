// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("麒麟[2;37;0m[2;37;0m", ({"sss"}));        
        set("gender", "男性");                
        set("long", "靈獸[2;37;0m
它是段無情的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "aia");
        set("owner_name", "段無情");
        set_temp("owner", "aia");
        set_temp("owner_name", "段無情");
        ::setup();
}
