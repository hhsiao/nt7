// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;33m大浪頭[2;37;0m[2;37;0m", ({"dlt"}));        
        set("gender", "男性");                
        set("long", "好大的浪頭[2;37;0m
它是無極拳頭的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "ljjwd");
        set("owner_name", "無極拳頭");
        set_temp("owner", "ljjwd");
        set_temp("owner_name", "無極拳頭");
        ::setup();
}
