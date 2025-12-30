// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("練放[2;37;0m[2;37;0m", ({"lidqa"}));        
        set("gender", "男性");                
        set("long", "練放[2;37;0m
它是煉蟲的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "lidq");
        set("owner_name", "煉蟲");
        set_temp("owner", "lidq");
        set_temp("owner_name", "煉蟲");
        ::setup();
}
