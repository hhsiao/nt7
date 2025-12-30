// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("兔子[2;37;0m[2;37;0m", ({"rabbit"}));        
        set("gender", "男性");                
        set("long", "一隻兔子[2;37;0m
它是劍雨的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "veryrain");
        set("owner_name", "劍雨");
        set_temp("owner", "veryrain");
        set_temp("owner_name", "劍雨");
        ::setup();
}
