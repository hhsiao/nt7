// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("霸下[2;37;0m[2;37;0m", ({"baxia"}));        
        set("gender", "男性");                
        set("long", "古龍之子[2;37;0m
它是青陽一一的魔幻獸。
");
        set("race_type", "玄武");
        set("magic/type", "water");
        set("owner", "qyyy");
        set("owner_name", "青陽一一");
        set_temp("owner", "qyyy");
        set_temp("owner_name", "青陽一一");
        ::setup();
}
