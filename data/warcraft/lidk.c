// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("練莫[2;37;0m[2;37;0m", ({"lidaa"}));        
        set("gender", "男性");                
        set("long", "練莫[2;37;0m
它是煉神的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "lidk");
        set("owner_name", "煉神");
        set_temp("owner", "lidk");
        set_temp("owner_name", "煉神");
        ::setup();
}
