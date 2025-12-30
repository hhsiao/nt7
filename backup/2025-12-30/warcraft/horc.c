// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("青龍[2;37;0m[2;37;0m", ({"qinglong"}));        
        set("gender", "男性");                
        set("long", "青龍[2;37;0m
它是東郭賢的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "horc");
        set("owner_name", "東郭賢");
        set_temp("owner", "horc");
        set_temp("owner_name", "東郭賢");
        ::setup();
}
