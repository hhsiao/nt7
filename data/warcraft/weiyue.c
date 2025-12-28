// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("白馬[2;37;0m[2;37;0m", ({"myhorse"}));        
        set("gender", "男性");                
        set("long", "白馬[2;37;0m
它是魏嶽的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "weiyue");
        set("owner_name", "魏嶽");
        set_temp("owner", "weiyue");
        set_temp("owner_name", "魏嶽");
        ::setup();
}
