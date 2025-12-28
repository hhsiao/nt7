// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("青龍[2;37;0m[2;37;0m", ({"long"}));        
        set("gender", "男性");                
        set("long", "青龍[2;37;0m
它是大腳世界的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "foot");
        set("owner_name", "大腳世界");
        set_temp("owner", "foot");
        set_temp("owner_name", "大腳世界");
        ::setup();
}
