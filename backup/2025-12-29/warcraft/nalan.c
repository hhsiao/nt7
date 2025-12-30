// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("兔子[2;37;0m[2;37;0m", ({"rabbit"}));        
        set("gender", "男性");                
        set("long", "一隻小兔子[2;37;0m
它是納蘭的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "nalan");
        set("owner_name", "納蘭");
        set_temp("owner", "nalan");
        set_temp("owner_name", "納蘭");
        ::setup();
}
