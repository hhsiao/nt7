// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;32m氤氳[2;37;0m[2;37;0m", ({"yinyun"}));        
        set("gender", "男性");                
        set("long", "爾其動也，風雨如晦，雷電共作；爾其靜也，體象皎鏡，星開碧落。[2;37;0m
它是碧落的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "biluo");
        set("owner_name", "碧落");
        set_temp("owner", "biluo");
        set_temp("owner_name", "碧落");
        ::setup();
}
