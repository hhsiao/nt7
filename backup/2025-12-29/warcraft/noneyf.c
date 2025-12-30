// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("麒麟[2;37;0m[2;37;0m", ({"noneys"}));        
        set("gender", "男性");                
        set("long", "麒麟[2;37;0m
它是錢孔通的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "noneyf");
        set("owner_name", "錢孔通");
        set_temp("owner", "noneyf");
        set_temp("owner_name", "錢孔通");
        ::setup();
}
