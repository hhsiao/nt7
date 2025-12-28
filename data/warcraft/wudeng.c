// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[5m[1;33m閃了你的眼[2;37;0m[2;37;0m", ({"wdds"}));        
        set("gender", "男性");                
        set("long", "又快又閃。[2;37;0m
它是五燈大師的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "wudeng");
        set("owner_name", "五燈大師");
        set_temp("owner", "wudeng");
        set_temp("owner_name", "五燈大師");
        ::setup();
}
