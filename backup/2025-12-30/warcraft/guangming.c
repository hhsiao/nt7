// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("瑞獸光明麒麟[2;37;0m[2;37;0m", ({"guangmingqilin"}));        
        set("gender", "男性");                
        set("long", "瑞獸光明麒麟[2;37;0m
它是張有悔的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "guangming");
        set("owner_name", "張有悔");
        set_temp("owner", "guangming");
        set_temp("owner_name", "張有悔");
        ::setup();
}
