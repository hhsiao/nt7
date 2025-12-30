// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;31m綠色螳螂[2;37;0m[2;37;0m", ({"larcs"}));        
        set("gender", "男性");                
        set("long", "我的寵物[2;37;0m
它是死緣的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "larc");
        set("owner_name", "死緣");
        set_temp("owner", "larc");
        set_temp("owner_name", "死緣");
        ::setup();
}
