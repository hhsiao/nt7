// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("巡航導彈[2;37;0m[2;37;0m", ({"croiser"}));        
        set("gender", "男性");                
        set("long", "巡航導彈[2;37;0m
它是空渡的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "mxr");
        set("owner_name", "空渡");
        set_temp("owner", "mxr");
        set_temp("owner_name", "空渡");
        ::setup();
}
