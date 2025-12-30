// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("龍[2;37;0m[2;37;0m", ({"long"}));        
        set("gender", "男性");                
        set("long", "龍[2;37;0m
它是金庸的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "simm");
        set("owner_name", "金庸");
        set_temp("owner", "simm");
        set_temp("owner_name", "金庸");
        ::setup();
}
