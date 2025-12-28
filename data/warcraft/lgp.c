// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("老狗評書[2;37;0m[2;37;0m", ({"lgps"}));        
        set("gender", "男性");                
        set("long", "哈哈[2;37;0m
它是老狗皮的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "lgp");
        set("owner_name", "老狗皮");
        set_temp("owner", "lgp");
        set_temp("owner_name", "老狗皮");
        ::setup();
}
