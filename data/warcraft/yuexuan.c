// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("土麒麟[2;37;0m[2;37;0m", ({"qilin"}));        
        set("gender", "男性");                
        set("long", "絕對防守、土麒麟[2;37;0m
它是月軒的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "yuexuan");
        set("owner_name", "月軒");
        set_temp("owner", "yuexuan");
        set_temp("owner_name", "月軒");
        ::setup();
}
