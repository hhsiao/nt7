// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("書架[2;37;0m[2;37;0m", ({"sleepbag"}));        
        set("gender", "男性");                
        set("long", "書架[2;37;0m
它是寶石砂的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "gems");
        set("owner_name", "寶石砂");
        set_temp("owner", "gems");
        set_temp("owner_name", "寶石砂");
        ::setup();
}
