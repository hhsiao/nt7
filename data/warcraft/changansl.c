// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("青龍[2;37;0m[2;37;0m", ({"qinglong"}));        
        set("gender", "男性");                
        set("long", "牛[2;37;0m
它是長六安的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "changansl");
        set("owner_name", "長六安");
        set_temp("owner", "changansl");
        set_temp("owner_name", "長六安");
        ::setup();
}
