// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("強大生物[2;37;0m[2;37;0m", ({"dalong"}));        
        set("gender", "女性");                
        set("long", "強大生物[2;37;0m
它是拿元寶的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "getall");
        set("owner_name", "拿元寶");
        set_temp("owner", "getall");
        set_temp("owner_name", "拿元寶");
        ::setup();
}
