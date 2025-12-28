// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("練衝[2;37;0m[2;37;0m", ({"lidoa"}));        
        set("gender", "男性");                
        set("long", "練衝[2;37;0m
它是煉草的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "lido");
        set("owner_name", "煉草");
        set_temp("owner", "lido");
        set_temp("owner_name", "煉草");
        ::setup();
}
