// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("哦訛誤哦[2;37;0m[2;37;0m", ({"cib"}));        
        set("gender", "男性");                
        set("long", "哦訛誤哦[2;37;0m
它是葡萄七號的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "lyg");
        set("owner_name", "葡萄七號");
        set_temp("owner", "lyg");
        set_temp("owner_name", "葡萄七號");
        ::setup();
}
