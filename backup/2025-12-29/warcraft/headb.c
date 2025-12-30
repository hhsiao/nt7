// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("夥子[2;37;0m[2;37;0m", ({"headblong"}));        
        set("gender", "男性");                
        set("long", "萬惡[2;37;0m
它是地方官員的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "headb");
        set("owner_name", "地方官員");
        set_temp("owner", "headb");
        set_temp("owner_name", "地方官員");
        ::setup();
}
