// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("小母龍[2;37;0m[2;37;0m", ({"mulong"}));        
        set("gender", "女性");                
        set("long", "$HIM$絕代嬌龍[2;37;0m
它是龍組長風的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "lst");
        set("owner_name", "龍組長風");
        set_temp("owner", "lst");
        set_temp("owner_name", "龍組長風");
        ::setup();
}
