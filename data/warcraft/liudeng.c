// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[5m[1;32m狂[1;33m飆[1;31m網[1;34m速[2;37;0m[2;37;0m", ({"ldds"}));        
        set("gender", "男性");                
        set("long", "快快快。[2;37;0m
它是六燈大師的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "liudeng");
        set("owner_name", "六燈大師");
        set_temp("owner", "liudeng");
        set_temp("owner_name", "六燈大師");
        ::setup();
}
