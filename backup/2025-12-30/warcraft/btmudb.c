// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("變獸二[2;37;0m[2;37;0m", ({"btb"}));        
        set("gender", "男性");                
        set("long", "爽[2;37;0m
它是變態米二的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "btmudb");
        set("owner_name", "變態米二");
        set_temp("owner", "btmudb");
        set_temp("owner_name", "變態米二");
        ::setup();
}
