// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;37m龍[2;37;0m[2;37;0m", ({"qlong"}));        
        set("gender", "男性");                
        set("long", "為劍而生 為劍而死[2;37;0m
它是鍾離劍的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "lijian");
        set("owner_name", "鍾離劍");
        set_temp("owner", "lijian");
        set_temp("owner_name", "鍾離劍");
        ::setup();
}
