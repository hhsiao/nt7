// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;35m龍寶寶[2;37;0m[2;37;0m", ({"longbaobao"}));        
        set("gender", "男性");                
        set("long", "一隻肥肥的龍寶寶[2;37;0m
它是獨孤一笑的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "dgyx");
        set("owner_name", "獨孤一笑");
        set_temp("owner", "dgyx");
        set_temp("owner_name", "獨孤一笑");
        ::setup();
}
