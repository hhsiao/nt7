// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("青龍[2;37;0m[2;37;0m", ({"qinglong"}));        
        set("gender", "男性");                
        set("long", "青龍[2;37;0m
它是慕容大的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "mrmr");
        set("owner_name", "慕容大");
        set_temp("owner", "mrmr");
        set_temp("owner_name", "慕容大");
        ::setup();
}
