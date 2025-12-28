// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("王語嫣[2;37;0m[2;37;0m", ({"dlalong"}));        
        set("gender", "男性");                
        set("long", "臥人[2;37;0m
它是賣靈感的魔幻獸。
");
        set("race_type", "玄武");
        set("magic/type", "water");
        set("owner", "dla");
        set("owner_name", "賣靈感");
        set_temp("owner", "dla");
        set_temp("owner_name", "賣靈感");
        ::setup();
}
