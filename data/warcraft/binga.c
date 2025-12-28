// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("豬缺[2;37;0m[2;37;0m", ({"tgd"}));        
        set("gender", "男性");                
        set("long", "sdfsdf[2;37;0m
它是輕兵的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "binga");
        set("owner_name", "輕兵");
        set_temp("owner", "binga");
        set_temp("owner_name", "輕兵");
        ::setup();
}
