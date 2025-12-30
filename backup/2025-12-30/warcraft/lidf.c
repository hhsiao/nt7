// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("狂放[2;37;0m[2;37;0m", ({"xaa"}));        
        set("gender", "男性");                
        set("long", "狂放[2;37;0m
它是煉火的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "lidf");
        set("owner_name", "煉火");
        set_temp("owner", "lidf");
        set_temp("owner_name", "煉火");
        ::setup();
}
