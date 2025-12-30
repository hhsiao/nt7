// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("麒麟[2;37;0m[2;37;0m", ({"esd"}));        
        set("gender", "女性");                
        set("long", "數學[2;37;0m
它是餘育的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "uio");
        set("owner_name", "餘育");
        set_temp("owner", "uio");
        set_temp("owner_name", "餘育");
        ::setup();
}
