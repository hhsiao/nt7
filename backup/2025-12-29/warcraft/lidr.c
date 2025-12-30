// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("練了[2;37;0m[2;37;0m", ({"lidra"}));        
        set("gender", "男性");                
        set("long", "練了[2;37;0m
它是煉川的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "lidr");
        set("owner_name", "煉川");
        set_temp("owner", "lidr");
        set_temp("owner_name", "煉川");
        ::setup();
}
