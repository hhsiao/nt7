// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("青龍[2;37;0m[2;37;0m", ({"qweasd"}));        
        set("gender", "男性");                
        set("long", "青龍[2;37;0m
它是硫磺少林的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "tgisl");
        set("owner_name", "硫磺少林");
        set_temp("owner", "tgisl");
        set_temp("owner_name", "硫磺少林");
        ::setup();
}
