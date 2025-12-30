// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[35m細雨如絲[2;37;0m[2;37;0m", ({"dranet"}));        
        set("gender", "男性");                
        set("long", "今生若不執子之手 待來生願與子偕老[2;37;0m
它是徐州柴火的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "wromfey");
        set("owner_name", "徐州柴火");
        set_temp("owner", "wromfey");
        set_temp("owner_name", "徐州柴火");
        ::setup();
}
