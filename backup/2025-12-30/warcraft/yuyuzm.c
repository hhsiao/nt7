// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("巨龍[2;37;0m[2;37;0m", ({"bailong"}));        
        set("gender", "男性");                
        set("long", "巨龍[2;37;0m
它是龍天的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "yuyuzm");
        set("owner_name", "龍天");
        set_temp("owner", "yuyuzm");
        set_temp("owner_name", "龍天");
        ::setup();
}
