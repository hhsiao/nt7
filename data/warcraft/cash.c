// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("車車車[2;37;0m[2;37;0m", ({"benz"}));        
        set("gender", "男性");                
        set("long", "                [2;37;0m
它是銀票的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "cash");
        set("owner_name", "銀票");
        set_temp("owner", "cash");
        set_temp("owner_name", "銀票");
        ::setup();
}
