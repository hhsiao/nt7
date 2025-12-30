// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("麒麟[2;37;0m[2;37;0m", ({"qilin"}));        
        set("gender", "男性");                
        set("long", "金光閃閃[2;37;0m
它是長八安的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "changanxy");
        set("owner_name", "長八安");
        set_temp("owner", "changanxy");
        set_temp("owner_name", "長八安");
        ::setup();
}
