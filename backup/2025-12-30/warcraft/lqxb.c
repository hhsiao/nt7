// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("交換機[2;37;0m[2;37;0m", ({"idsds"}));        
        set("gender", "女性");                
        set("long", "交換機叫姐姐[2;37;0m
它是哦點的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "lqxb");
        set("owner_name", "哦點");
        set_temp("owner", "lqxb");
        set_temp("owner_name", "哦點");
        ::setup();
}
