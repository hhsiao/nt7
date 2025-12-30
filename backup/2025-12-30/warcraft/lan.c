// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;32m青龍[2;37;0m[2;37;0m", ({"qinglong"}));        
        set("gender", "男性");                
        set("long", "青龍[2;37;0m
它是米蘭的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "lan");
        set("owner_name", "米蘭");
        set_temp("owner", "lan");
        set_temp("owner_name", "米蘭");
        ::setup();
}
