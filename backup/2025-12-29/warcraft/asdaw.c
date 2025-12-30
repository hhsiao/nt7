// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[5m[1;37m御[1;36m[5m風[1;31m[5m青[1;33m[5m龍[2;37;0m[2;37;0m", ({"qinglong"}));        
        set("gender", "男性");                
        set("long", "青龍[2;37;0m
它是彷彿額的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "asdaw");
        set("owner_name", "彷彿額");
        set_temp("owner", "asdaw");
        set_temp("owner_name", "彷彿額");
        ::setup();
}
