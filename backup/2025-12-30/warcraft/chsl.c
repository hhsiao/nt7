// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("麒麟[2;37;0m[2;37;0m", ({"bibi"}));        
        set("gender", "男性");                
        set("long", "麒麟[2;37;0m
它是少琳的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "chsl");
        set("owner_name", "少琳");
        set_temp("owner", "chsl");
        set_temp("owner_name", "少琳");
        ::setup();
}
