// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("麒麟[2;37;0m[2;37;0m", ({"lana"}));        
        set("gender", "男性");                
        set("long", "麒麟[2;37;0m
它是丁蘭的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "lanxx");
        set("owner_name", "丁蘭");
        set_temp("owner", "lanxx");
        set_temp("owner_name", "丁蘭");
        ::setup();
}
