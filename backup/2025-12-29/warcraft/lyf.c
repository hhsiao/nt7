// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("離開圍毆[2;37;0m[2;37;0m", ({"cib"}));        
        set("gender", "男性");                
        set("long", "離開圍毆[2;37;0m
它是葡萄六號的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "lyf");
        set("owner_name", "葡萄六號");
        set_temp("owner", "lyf");
        set_temp("owner_name", "葡萄六號");
        ::setup();
}
