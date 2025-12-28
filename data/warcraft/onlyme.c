// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("青龍[2;37;0m[2;37;0m", ({"pet"}));        
        set("gender", "男性");                
        set("long", "qinglong[2;37;0m
它是楊楊的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "onlyme");
        set("owner_name", "楊楊");
        set_temp("owner", "onlyme");
        set_temp("owner_name", "楊楊");
        ::setup();
}
