// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("青龍[2;37;0m[2;37;0m", ({"ddddd"}));        
        set("gender", "男性");                
        set("long", "青龍[2;37;0m
它是啊大的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "ddda");
        set("owner_name", "啊大");
        set_temp("owner", "ddda");
        set_temp("owner_name", "啊大");
        ::setup();
}
