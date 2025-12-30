// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("老狗拜師[2;37;0m[2;37;0m", ({"lgbs"}));        
        set("gender", "男性");                
        set("long", "哈哈[2;37;0m
它是老狗貳的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "lgb");
        set("owner_name", "老狗貳");
        set_temp("owner", "lgb");
        set_temp("owner_name", "老狗貳");
        ::setup();
}
