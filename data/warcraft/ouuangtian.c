// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("飛飛[2;37;0m[2;37;0m", ({"ouu"}));        
        set("gender", "男性");                
        set("long", "============[2;37;0m
它是歐陽天的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "ouuangtian");
        set("owner_name", "歐陽天");
        set_temp("owner", "ouuangtian");
        set_temp("owner_name", "歐陽天");
        ::setup();
}
