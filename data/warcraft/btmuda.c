// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("變獸一[2;37;0m[2;37;0m", ({"bta"}));        
        set("gender", "男性");                
        set("long", "雙[2;37;0m
它是變態米一的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "btmuda");
        set("owner_name", "變態米一");
        set_temp("owner", "btmuda");
        set_temp("owner_name", "變態米一");
        ::setup();
}
