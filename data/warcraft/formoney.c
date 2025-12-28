// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("睡睡[2;37;0m[2;37;0m", ({"sleepbag"}));        
        set("gender", "男性");                
        set("long", "睡睡[2;37;0m
它是為了錢的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "formoney");
        set("owner_name", "為了錢");
        set_temp("owner", "formoney");
        set_temp("owner_name", "為了錢");
        ::setup();
}
