// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("蕭天[2;37;0m[2;37;0m", ({"tian"}));        
        set("gender", "男性");                
        set("long", "-------------[2;37;0m
它是天遠的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "tianyuan");
        set("owner_name", "天遠");
        set_temp("owner", "tianyuan");
        set_temp("owner_name", "天遠");
        ::setup();
}
