// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("雲虎[2;37;0m[2;37;0m", ({"mycar"}));        
        set("gender", "男性");                
        set("long", "吳[2;37;0m
它是楚北雲的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "zbdm");
        set("owner_name", "楚北雲");
        set_temp("owner", "zbdm");
        set_temp("owner_name", "楚北雲");
        ::setup();
}
