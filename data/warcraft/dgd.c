// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("母雞[2;37;0m[2;37;0m", ({"dft"}));        
        set("gender", "男性");                
        set("long", "母雞[2;37;0m
它是歐陽四的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "dgd");
        set("owner_name", "歐陽四");
        set_temp("owner", "dgd");
        set_temp("owner_name", "歐陽四");
        ::setup();
}
