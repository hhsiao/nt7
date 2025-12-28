// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[5m[1;31m當[1;32m裡[1;36m個[1;31m當[2;37;0m[2;37;0m", ({"dang"}));        
        set("gender", "男性");                
        set("long", "當哩個來當，當裡個當，當裡個當來當裡個當！[2;37;0m
它是武當的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "wudang");
        set("owner_name", "武當");
        set_temp("owner", "wudang");
        set_temp("owner_name", "武當");
        ::setup();
}
