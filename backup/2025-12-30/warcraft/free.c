// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("青龍[2;37;0m[2;37;0m", ({"ddddd"}));        
        set("gender", "男性");                
        set("long", "青龍[2;37;0m
它是何自由的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "free");
        set("owner_name", "何自由");
        set_temp("owner", "free");
        set_temp("owner_name", "何自由");
        ::setup();
}
