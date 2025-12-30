// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("沙發[2;37;0m[2;37;0m", ({"mmx"}));        
        set("gender", "男性");                
        set("long", "111[2;37;0m
它是掃地的魔幻獸。
");
        set("race_type", "玄武");
        set("magic/type", "water");
        set("owner", "xmm");
        set("owner_name", "掃地");
        set_temp("owner", "xmm");
        set_temp("owner_name", "掃地");
        ::setup();
}
