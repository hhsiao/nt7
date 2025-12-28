// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;34m門堪三雀[2;37;0m[2;37;0m", ({"woc"}));        
        set("gender", "男性");                
        set("long", "門堪三雀!!![2;37;0m
它是夜叄的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "wocc");
        set("owner_name", "夜叄");
        set_temp("owner", "wocc");
        set_temp("owner_name", "夜叄");
        ::setup();
}
