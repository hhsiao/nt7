// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("白虎[2;37;0m[2;37;0m", ({"baihu"}));        
        set("gender", "男性");                
        set("long", "白虎[2;37;0m
它是郝連水的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "skpg");
        set("owner_name", "郝連水");
        set_temp("owner", "skpg");
        set_temp("owner_name", "郝連水");
        ::setup();
}
