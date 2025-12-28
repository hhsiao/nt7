// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("麒麟[2;37;0m[2;37;0m", ({"noneys"}));        
        set("gender", "男性");                
        set("long", "麒麟[2;37;0m
它是錢不通的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "noneyj");
        set("owner_name", "錢不通");
        set_temp("owner", "noneyj");
        set_temp("owner_name", "錢不通");
        ::setup();
}
