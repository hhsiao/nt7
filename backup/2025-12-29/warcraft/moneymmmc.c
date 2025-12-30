// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("騾子[2;37;0m[2;37;0m", ({"luozi"}));        
        set("gender", "男性");                
        set("long", "騾子[2;37;0m
它是錢可多的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "moneymmmc");
        set("owner_name", "錢可多");
        set_temp("owner", "moneymmmc");
        set_temp("owner_name", "錢可多");
        ::setup();
}
