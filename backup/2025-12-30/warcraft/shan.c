// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;36m湛藍神獸[2;37;0m[2;37;0m", ({"shan_dragon"}));        
        set("gender", "男性");                
        set("long", "一隻渾身散發淡淡微光的神獸，據說是天地第一道光所化。[2;37;0m
它是青衫隱隱的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "shan");
        set("owner_name", "青衫隱隱");
        set_temp("owner", "shan");
        set_temp("owner_name", "青衫隱隱");
        ::setup();
}
