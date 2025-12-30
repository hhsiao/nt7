// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("青龍[2;37;0m[2;37;0m", ({"mycar"}));        
        set("gender", "男性");                
        set("long", "無[2;37;0m
它是工人一的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "gonga");
        set("owner_name", "工人一");
        set_temp("owner", "gonga");
        set_temp("owner_name", "工人一");
        ::setup();
}
