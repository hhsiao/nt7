// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;33m忽忽[2;37;0m[2;37;0m", ({"shenaa"}));        
        set("gender", "男性");                
        set("long", "這是忽忽[2;37;0m
它是蛇飛色的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "shena");
        set("owner_name", "蛇飛色");
        set_temp("owner", "shena");
        set_temp("owner_name", "蛇飛色");
        ::setup();
}
