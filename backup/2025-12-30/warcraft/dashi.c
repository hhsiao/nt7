// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[5m[1;36m小[1;35m沙[1;32m彌[2;37;0m[2;37;0m", ({"shami"}));        
        set("gender", "女性");                
        set("long", "$BLINK$$HIC$小$HIM$沙$HIG$彌[2;37;0m
它是一燈大師的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "dashi");
        set("owner_name", "一燈大師");
        set_temp("owner", "dashi");
        set_temp("owner_name", "一燈大師");
        ::setup();
}
