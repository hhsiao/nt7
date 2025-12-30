// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("圖[2;37;0m[2;37;0m", ({"ttb"}));        
        set("gender", "男性");                
        set("long", "xx[2;37;0m
它是圖二的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "ttzb");
        set("owner_name", "圖二");
        set_temp("owner", "ttzb");
        set_temp("owner_name", "圖二");
        ::setup();
}
