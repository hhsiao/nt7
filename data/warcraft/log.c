// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("雨[2;37;0m[2;37;0m", ({"logo"}));        
        set("gender", "女性");                
        set("long", "   [2;37;0m
它是精力無限的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "log");
        set("owner_name", "精力無限");
        set_temp("owner", "log");
        set_temp("owner_name", "精力無限");
        ::setup();
}
