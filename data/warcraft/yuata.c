// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("麒麟[2;37;0m[2;37;0m", ({"yuqi"}));        
        set("gender", "男性");                
        set("long", "麒麟[2;37;0m
它是歐陽樊的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "yuata");
        set("owner_name", "歐陽樊");
        set_temp("owner", "yuata");
        set_temp("owner_name", "歐陽樊");
        ::setup();
}
