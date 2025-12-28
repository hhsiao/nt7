// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("神仙龍[2;37;0m[2;37;0m", ({"shengou"}));        
        set("gender", "男性");                
        set("long", "神仙龍[2;37;0m
它是夏天的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "sghdxmc");
        set("owner_name", "夏天");
        set_temp("owner", "sghdxmc");
        set_temp("owner_name", "夏天");
        ::setup();
}
