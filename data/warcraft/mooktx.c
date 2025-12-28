// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("神獸玄武[2;37;0m[2;37;0m", ({"xuanwu"}));        
        set("gender", "男性");                
        set("long", "一隻神獸玄武。[2;37;0m
它是清水的魔幻獸。
");
        set("race_type", "玄武");
        set("magic/type", "water");
        set("owner", "mooktx");
        set("owner_name", "清水");
        set_temp("owner", "mooktx");
        set_temp("owner_name", "清水");
        ::setup();
}
