// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[33m二狗子[2;37;0m[2;37;0m", ({"sleepbag"}));        
        set("gender", "男性");                
        set("long", "二狗子[2;37;0m
它是麥地的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "mighty");
        set("owner_name", "麥地");
        set_temp("owner", "mighty");
        set_temp("owner_name", "麥地");
        ::setup();
}
