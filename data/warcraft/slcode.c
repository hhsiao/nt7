// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[37m五色牛[2;37;0m[2;37;0m", ({"niu"}));        
        set("gender", "男性");                
        set("long", "五色牛[2;37;0m
它是靈臺靈活的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "slcode");
        set("owner_name", "靈臺靈活");
        set_temp("owner", "slcode");
        set_temp("owner_name", "靈臺靈活");
        ::setup();
}
