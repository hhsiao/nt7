// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("卡羅拉[2;37;0m[2;37;0m", ({"corolla"}));        
        set("gender", "女性");                
        set("long", "卡羅拉[2;37;0m
它是鸕咔的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "luka");
        set("owner_name", "鸕咔");
        set_temp("owner", "luka");
        set_temp("owner_name", "鸕咔");
        ::setup();
}
