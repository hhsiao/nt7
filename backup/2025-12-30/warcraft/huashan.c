// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("看[2;37;0m[2;37;0m", ({"sss"}));        
        set("gender", "男性");                
        set("long", "看[2;37;0m
它是打開是的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "huashan");
        set("owner_name", "打開是");
        set_temp("owner", "huashan");
        set_temp("owner_name", "打開是");
        ::setup();
}
