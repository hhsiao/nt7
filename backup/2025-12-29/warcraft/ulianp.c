// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[35m墨魚[2;37;0m[2;37;0m", ({"mql"}));        
        set("gender", "男性");                
        set("long", "墨魚墨魚[2;37;0m
它是遙丙的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "ulianp");
        set("owner_name", "遙丙");
        set_temp("owner", "ulianp");
        set_temp("owner_name", "遙丙");
        ::setup();
}
