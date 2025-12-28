// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("山地[2;37;0m[2;37;0m", ({"benz"}));        
        set("gender", "女性");                
        set("long", "           [2;37;0m
它是龍一的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "longa");
        set("owner_name", "龍一");
        set_temp("owner", "longa");
        set_temp("owner_name", "龍一");
        ::setup();
}
