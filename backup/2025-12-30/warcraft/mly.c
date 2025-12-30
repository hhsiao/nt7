// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("飽飽[2;37;0m[2;37;0m", ({"bryan"}));        
        set("gender", "男性");                
        set("long", "我是寶寶。[2;37;0m
它是歐陽春的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "mly");
        set("owner_name", "歐陽春");
        set_temp("owner", "mly");
        set_temp("owner_name", "歐陽春");
        ::setup();
}
