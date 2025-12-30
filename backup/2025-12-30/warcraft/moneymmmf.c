// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("騾子[2;37;0m[2;37;0m", ({"luozi"}));        
        set("gender", "男性");                
        set("long", "騾子[2;37;0m
它是錢無得的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "moneymmmf");
        set("owner_name", "錢無得");
        set_temp("owner", "moneymmmf");
        set_temp("owner_name", "錢無得");
        ::setup();
}
