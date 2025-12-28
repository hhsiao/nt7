// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("青青[2;37;0m[2;37;0m", ({"dydxgqq"}));        
        set("gender", "女性");                
        set("long", "肥肥胖胖[2;37;0m
它是蓮心曉夢的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "dydxgq");
        set("owner_name", "蓮心曉夢");
        set_temp("owner", "dydxgq");
        set_temp("owner_name", "蓮心曉夢");
        ::setup();
}
