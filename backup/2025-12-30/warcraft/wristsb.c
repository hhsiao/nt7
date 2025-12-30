// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("我黨[2;37;0m[2;37;0m", ({"along"}));        
        set("gender", "男性");                
        set("long", "無法[2;37;0m
它是大華山的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "wristsb");
        set("owner_name", "大華山");
        set_temp("owner", "wristsb");
        set_temp("owner_name", "大華山");
        ::setup();
}
