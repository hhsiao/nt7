// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;35m墨魚[2;37;0m[2;37;0m", ({"mql"}));        
        set("gender", "女性");                
        set("long", "墨魚噢[2;37;0m
它是光頭強的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "ulianc");
        set("owner_name", "光頭強");
        set_temp("owner", "ulianc");
        set_temp("owner_name", "光頭強");
        ::setup();
}
