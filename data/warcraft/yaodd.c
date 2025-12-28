// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("打堆堆[2;37;0m[2;37;0m", ({"yaoddd"}));        
        set("gender", "男性");                
        set("long", "ddd[2;37;0m
它是藥滴滴的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "yaodd");
        set("owner_name", "藥滴滴");
        set_temp("owner", "yaodd");
        set_temp("owner_name", "藥滴滴");
        ::setup();
}
