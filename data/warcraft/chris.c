// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("青龍[2;37;0m[2;37;0m", ({"qinglong"}));        
        set("gender", "男性");                
        set("long", "勇氣、智慧與美麗於一身的強大生物。[2;37;0m
它是海程的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "chris");
        set("owner_name", "海程");
        set_temp("owner", "chris");
        set_temp("owner_name", "海程");
        ::setup();
}
