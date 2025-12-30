// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("一條大龍[2;37;0m[2;37;0m", ({"cobuybb"}));        
        set("gender", "男性");                
        set("long", "一條大龍啊[2;37;0m
它是白色的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "cobuyb");
        set("owner_name", "白色");
        set_temp("owner", "cobuyb");
        set_temp("owner_name", "白色");
        ::setup();
}
