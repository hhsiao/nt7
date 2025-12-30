// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("買藥商麒麟[2;37;0m[2;37;0m", ({"buydrugqilin"}));        
        set("gender", "男性");                
        set("long", "買藥商麒麟[2;37;0m
它是供藥商的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "buydrug");
        set("owner_name", "供藥商");
        set_temp("owner", "buydrug");
        set_temp("owner_name", "供藥商");
        ::setup();
}
