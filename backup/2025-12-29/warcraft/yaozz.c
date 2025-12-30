// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("麒麟[2;37;0m[2;37;0m", ({"yaozzz"}));        
        set("gender", "男性");                
        set("long", "麒麟[2;37;0m
它是藥製作的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "yaozz");
        set("owner_name", "藥製作");
        set_temp("owner", "yaozz");
        set_temp("owner_name", "藥製作");
        ::setup();
}
