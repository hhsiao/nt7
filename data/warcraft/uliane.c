// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;35m墨魚[2;37;0m[2;37;0m", ({"mql"}));        
        set("gender", "男性");                
        set("long", "墨魚噢[2;37;0m
它是熊二的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "uliane");
        set("owner_name", "熊二");
        set_temp("owner", "uliane");
        set_temp("owner_name", "熊二");
        ::setup();
}
