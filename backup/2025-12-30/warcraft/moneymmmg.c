// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("騾子[2;37;0m[2;37;0m", ({"luozi"}));        
        set("gender", "男性");                
        set("long", "騾子[2;37;0m
它是錢眼多的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "moneymmmg");
        set("owner_name", "錢眼多");
        set_temp("owner", "moneymmmg");
        set_temp("owner_name", "錢眼多");
        ::setup();
}
