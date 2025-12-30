// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;31m死亡之吼[2;37;0m[2;37;0m", ({"laoma"}));        
        set("gender", "男性");                
        set("long", "死亡之吼[2;37;0m
它是蟲二的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "enjoy");
        set("owner_name", "蟲二");
        set_temp("owner", "enjoy");
        set_temp("owner_name", "蟲二");
        ::setup();
}
