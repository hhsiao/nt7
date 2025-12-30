// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("青龍[2;37;0m[2;37;0m", ({"qinglong"}));        
        set("gender", "男性");                
        set("long", "青龍[2;37;0m
它是任五的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "ttt");
        set("owner_name", "任五");
        set_temp("owner", "ttt");
        set_temp("owner_name", "任五");
        ::setup();
}
