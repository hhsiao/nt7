// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[5m[1;31m正七訣[2;37;0m[2;37;0m", ({"zqj"}));        
        set("gender", "男性");                
        set("long", "出差華山那書。[2;37;0m
它是七覺正的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "zhengqijue");
        set("owner_name", "七覺正");
        set_temp("owner", "zhengqijue");
        set_temp("owner_name", "七覺正");
        ::setup();
}
