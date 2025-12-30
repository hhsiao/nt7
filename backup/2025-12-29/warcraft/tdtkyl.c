// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("貝貝[2;37;0m[2;37;0m", ({"tjwxczq"}));        
        set("gender", "男性");                
        set("long", "小貝貝[2;37;0m
它是曉飛的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "tdtkyl");
        set("owner_name", "曉飛");
        set_temp("owner", "tdtkyl");
        set_temp("owner_name", "曉飛");
        ::setup();
}
