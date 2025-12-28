// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("老狗發燒[2;37;0m[2;37;0m", ({"lgfs"}));        
        set("gender", "男性");                
        set("long", "哈哈[2;37;0m
它是老狗陸的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "lgf");
        set("owner_name", "老狗陸");
        set_temp("owner", "lgf");
        set_temp("owner_name", "老狗陸");
        ::setup();
}
