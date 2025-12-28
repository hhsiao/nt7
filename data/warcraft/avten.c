// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("青龍[2;37;0m[2;37;0m", ({"qinlong"}));        
        set("gender", "男性");                
        set("long", "青龍[2;37;0m
它是瀧澤老師的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "avten");
        set("owner_name", "瀧澤老師");
        set_temp("owner", "avten");
        set_temp("owner_name", "瀧澤老師");
        ::setup();
}
