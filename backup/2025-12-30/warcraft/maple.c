// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("麒麟[2;37;0m[2;37;0m", ({"mmp"}));        
        set("gender", "女性");                
        set("long", "麒麟[2;37;0m
它是楓飛揚的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "maple");
        set("owner_name", "楓飛揚");
        set_temp("owner", "maple");
        set_temp("owner_name", "楓飛揚");
        ::setup();
}
