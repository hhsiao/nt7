// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("馬兒跑[2;37;0m[2;37;0m", ({"maerpao"}));        
        set("gender", "女性");                
        set("long", "馬兒跑[2;37;0m
它是極無極的魔幻獸。
");
        set("race_type", "玄武");
        set("magic/type", "water");
        set("owner", "driver");
        set("owner_name", "極無極");
        set_temp("owner", "driver");
        set_temp("owner_name", "極無極");
        ::setup();
}
