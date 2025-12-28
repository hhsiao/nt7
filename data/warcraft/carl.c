// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("小龍女[2;37;0m[2;37;0m", ({"carlql"}));        
        set("gender", "女性");                
        set("long", "一條母龍[2;37;0m
它是耿照的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "carl");
        set("owner_name", "耿照");
        set_temp("owner", "carl");
        set_temp("owner_name", "耿照");
        ::setup();
}
