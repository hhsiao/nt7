// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("麒麟[2;37;0m[2;37;0m", ({"ccjj"}));        
        set("gender", "男性");                
        set("long", "麒麟[2;37;0m
它是學就的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "ccj");
        set("owner_name", "學就");
        set_temp("owner", "ccj");
        set_temp("owner_name", "學就");
        ::setup();
}
