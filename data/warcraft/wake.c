// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("青龍[2;37;0m[2;37;0m", ({"xiaoq"}));        
        set("gender", "男性");                
        set("long", "青龍[2;37;0m
它是摩訶的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "wake");
        set("owner_name", "摩訶");
        set_temp("owner", "wake");
        set_temp("owner_name", "摩訶");
        ::setup();
}
