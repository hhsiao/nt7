// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("驃騎[2;37;0m[2;37;0m", ({"xbiaoshib"}));        
        set("gender", "女性");                
        set("long", "驃騎[2;37;0m
它是鏢師二的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "biaoshib");
        set("owner_name", "鏢師二");
        set_temp("owner", "biaoshib");
        set_temp("owner_name", "鏢師二");
        ::setup();
}
