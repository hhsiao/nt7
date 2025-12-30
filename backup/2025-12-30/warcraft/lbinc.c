// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("大龍[2;37;0m[2;37;0m", ({"dalong"}));        
        set("gender", "男性");                
        set("long", "大龍[2;37;0m
它是張四的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "lbinc");
        set("owner_name", "張四");
        set_temp("owner", "lbinc");
        set_temp("owner_name", "張四");
        ::setup();
}
