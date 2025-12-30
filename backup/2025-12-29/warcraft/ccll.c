// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("麒麟[2;37;0m[2;37;0m", ({"cclll"}));        
        set("gender", "男性");                
        set("long", "麒麟[2;37;0m
它是學啦的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "ccll");
        set("owner_name", "學啦");
        set_temp("owner", "ccll");
        set_temp("owner_name", "學啦");
        ::setup();
}
