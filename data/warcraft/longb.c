// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("帶我[2;37;0m[2;37;0m", ({"benz"}));        
        set("gender", "男性");                
        set("long", "          [2;37;0m
它是龍二的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "longb");
        set("owner_name", "龍二");
        set_temp("owner", "longb");
        set_temp("owner_name", "龍二");
        ::setup();
}
