// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("變獸四[2;37;0m[2;37;0m", ({"btd"}));        
        set("gender", "男性");                
        set("long", "爽[2;37;0m
它是變態米四的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "btmudd");
        set("owner_name", "變態米四");
        set_temp("owner", "btmudd");
        set_temp("owner_name", "變態米四");
        ::setup();
}
