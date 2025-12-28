// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("練放[2;37;0m[2;37;0m", ({"lidll"}));        
        set("gender", "男性");                
        set("long", "練放[2;37;0m
它是煉土的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "lidl");
        set("owner_name", "煉土");
        set_temp("owner", "lidl");
        set_temp("owner_name", "煉土");
        ::setup();
}
