// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("麒麟[2;37;0m[2;37;0m", ({"yaottt"}));        
        set("gender", "男性");                
        set("long", "麒麟[2;37;0m
它是藥鐵塔的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "yaott");
        set("owner_name", "藥鐵塔");
        set_temp("owner", "yaott");
        set_temp("owner_name", "藥鐵塔");
        ::setup();
}
