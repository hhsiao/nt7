// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;34m饕餮[2;37;0m[2;37;0m", ({"taotie"}));        
        set("gender", "男性");                
        set("long", "。。。[2;37;0m
它是星劍的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "count");
        set("owner_name", "星劍");
        set_temp("owner", "count");
        set_temp("owner_name", "星劍");
        ::setup();
}
