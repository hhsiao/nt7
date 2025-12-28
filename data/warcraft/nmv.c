// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("泥煤[2;37;0m[2;37;0m", ({"nmride"}));        
        set("gender", "女性");                
        set("long", "泥煤[2;37;0m
它是餘晴灣彎的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "nmv");
        set("owner_name", "餘晴灣彎");
        set_temp("owner", "nmv");
        set_temp("owner_name", "餘晴灣彎");
        ::setup();
}
