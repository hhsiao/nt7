// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("框[2;37;0m[2;37;0m", ({"kuangkuang"}));        
        set("gender", "男性");                
        set("long", "框[2;37;0m
它是戲紅塵的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "hongchen");
        set("owner_name", "戲紅塵");
        set_temp("owner", "hongchen");
        set_temp("owner_name", "戲紅塵");
        ::setup();
}
