// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[5m[1;32m一[1;33m閃[1;36m閃[2;37;0m[2;37;0m", ({"flashs"}));        
        set("gender", "女性");                
        set("long", "閃閃龍[2;37;0m
它是依韻的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "unchichi");
        set("owner_name", "依韻");
        set_temp("owner", "unchichi");
        set_temp("owner_name", "依韻");
        ::setup();
}
