// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("青龍[2;37;0m[2;37;0m", ({"qinglong"}));        
        set("gender", "女性");                
        set("long", "青龍[2;37;0m
它是秦倚天的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "xyfd");
        set("owner_name", "秦倚天");
        set_temp("owner", "xyfd");
        set_temp("owner_name", "秦倚天");
        ::setup();
}
