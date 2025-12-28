// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("太陽神鳥[2;37;0m[2;37;0m", ({"birdman"}));        
        set("gender", "男性");                
        set("long", "太陽神鳥[2;37;0m
它是血色太陽的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "scdyzxd");
        set("owner_name", "血色太陽");
        set_temp("owner", "scdyzxd");
        set_temp("owner_name", "血色太陽");
        ::setup();
}
