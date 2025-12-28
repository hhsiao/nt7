// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[5m[36m極[1;31m品[33m饅[1;37m頭[2;37;0m[2;37;0m", ({"laohu"}));        
        set("gender", "男性");                
        set("long", "女職工[2;37;0m
它是嚮往自由的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "tma");
        set("owner_name", "嚮往自由");
        set_temp("owner", "tma");
        set_temp("owner_name", "嚮往自由");
        ::setup();
}
