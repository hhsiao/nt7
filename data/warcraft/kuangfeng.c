// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;32m風龍[2;37;0m[2;37;0m", ({"feng"}));        
        set("gender", "男性");                
        set("long", "風龍[2;37;0m
它是狂風的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "kuangfeng");
        set("owner_name", "狂風");
        set_temp("owner", "kuangfeng");
        set_temp("owner_name", "狂風");
        ::setup();
}
