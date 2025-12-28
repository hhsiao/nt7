// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("飛車[2;37;0m[2;37;0m", ({"mycar"}));        
        set("gender", "女性");                
        set("long", "無[2;37;0m
它是楚北風的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "zbd");
        set("owner_name", "楚北風");
        set_temp("owner", "zbd");
        set_temp("owner_name", "楚北風");
        ::setup();
}
