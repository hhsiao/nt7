// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("流星雨[2;37;0m[2;37;0m", ({"tsk"}));        
        set("gender", "男性");                
        set("long", "許個願，或許有天它會實現...。[2;37;0m
它是麻辣教師的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "gto");
        set("owner_name", "麻辣教師");
        set_temp("owner", "gto");
        set_temp("owner_name", "麻辣教師");
        ::setup();
}
