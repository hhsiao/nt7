// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("白虎[2;37;0m[2;37;0m", ({"baihu"}));        
        set("gender", "女性");                
        set("long", "白虎[2;37;0m
它是北宮海的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "jlff");
        set("owner_name", "北宮海");
        set_temp("owner", "jlff");
        set_temp("owner_name", "北宮海");
        ::setup();
}
