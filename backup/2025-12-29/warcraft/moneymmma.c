// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("騾子[2;37;0m[2;37;0m", ({"luozi"}));        
        set("gender", "男性");                
        set("long", "騾子[2;37;0m
它是錢超多的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "moneymmma");
        set("owner_name", "錢超多");
        set_temp("owner", "moneymmma");
        set_temp("owner_name", "錢超多");
        ::setup();
}
