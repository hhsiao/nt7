// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("九陽[2;37;0m[2;37;0m", ({"sleepbag"}));        
        set("gender", "男性");                
        set("long", "九陽[2;37;0m
它是九陽神功的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "cba");
        set("owner_name", "九陽神功");
        set_temp("owner", "cba");
        set_temp("owner_name", "九陽神功");
        ::setup();
}
