// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[46;1m[1;32m小不丁點[2;37;0m[2;37;0m", ({"xxoo"}));        
        set("gender", "男性");                
        set("long", "一隻快樂的小布丁。[2;37;0m
它是繆斯的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "mousai");
        set("owner_name", "繆斯");
        set_temp("owner", "mousai");
        set_temp("owner_name", "繆斯");
        ::setup();
}
