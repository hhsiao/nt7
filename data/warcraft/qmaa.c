// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;31m九陽大神功[2;37;0m[2;37;0m", ({"qmaaa"}));        
        set("gender", "男性");                
        set("long", "九陽大神功[2;37;0m
它是九陽去拿的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "qmaa");
        set("owner_name", "九陽去拿");
        set_temp("owner", "qmaa");
        set_temp("owner_name", "九陽去拿");
        ::setup();
}
