// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;37m太白[2;37;0m[2;37;0m", ({"atx"}));        
        set("gender", "女性");                
        set("long", "天乙神酒[2;37;0m
它是李白的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "libai");
        set("owner_name", "李白");
        set_temp("owner", "libai");
        set_temp("owner_name", "李白");
        ::setup();
}
