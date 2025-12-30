// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("啪啪啪[2;37;0m[2;37;0m", ({"qinglong"}));        
        set("gender", "男性");                
        set("long", "砰砰砰[2;37;0m
它是東風三號的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "workb");
        set("owner_name", "東風三號");
        set_temp("owner", "workb");
        set_temp("owner_name", "東風三號");
        ::setup();
}
