// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("騾子[2;37;0m[2;37;0m", ({"luozi"}));        
        set("gender", "男性");                
        set("long", "騾子[2;37;0m
它是錢無量的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "moneymmmd");
        set("owner_name", "錢無量");
        set_temp("owner", "moneymmmd");
        set_temp("owner_name", "錢無量");
        ::setup();
}
