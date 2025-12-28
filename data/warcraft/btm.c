// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("多多[2;37;0m[2;37;0m", ({"btmxw"}));        
        set("gender", "男性");                
        set("long", "多了一個[2;37;0m
它是半條命的魔幻獸。
");
        set("race_type", "玄武");
        set("magic/type", "water");
        set("owner", "btm");
        set("owner_name", "半條命");
        set_temp("owner", "btm");
        set_temp("owner_name", "半條命");
        ::setup();
}
