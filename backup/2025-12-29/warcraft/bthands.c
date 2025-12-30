// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("小香豬[2;37;0m[2;37;0m", ({"xxz"}));        
        set("gender", "男性");                
        set("long", "小香豬[2;37;0m
它是不通侍掌的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "bthands");
        set("owner_name", "不通侍掌");
        set_temp("owner", "bthands");
        set_temp("owner_name", "不通侍掌");
        ::setup();
}
