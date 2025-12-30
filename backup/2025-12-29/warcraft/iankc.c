// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("豐[2;37;0m[2;37;0m", ({"horse"}));        
        set("gender", "男性");                
        set("long", "豐[2;37;0m
它是二風的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "iankc");
        set("owner_name", "二風");
        set_temp("owner", "iankc");
        set_temp("owner_name", "二風");
        ::setup();
}
