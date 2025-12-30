// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("徐[2;37;0m[2;37;0m", ({"shou"}));        
        set("gender", "男性");                
        set("long", "渡[2;37;0m
它是徐渡的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "minizsb");
        set("owner_name", "徐渡");
        set_temp("owner", "minizsb");
        set_temp("owner_name", "徐渡");
        ::setup();
}
