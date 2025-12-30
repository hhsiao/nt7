// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("馬[2;37;0m[2;37;0m", ({"horse"}));        
        set("gender", "男性");                
        set("long", "一匹馬[2;37;0m
它是木晨的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "unable");
        set("owner_name", "木晨");
        set_temp("owner", "unable");
        set_temp("owner_name", "木晨");
        ::setup();
}
