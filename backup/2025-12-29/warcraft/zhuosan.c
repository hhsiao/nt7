// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;36m小糊塗蟲[2;37;0m[2;37;0m", ({"mazebug"}));        
        set("gender", "男性");                
        set("long", "難得糊塗，糊塗難得！！！[2;37;0m
它是卓太航的魔幻獸。
");
        set("race_type", "玄武");
        set("magic/type", "water");
        set("owner", "zhuosan");
        set("owner_name", "卓太航");
        set_temp("owner", "zhuosan");
        set_temp("owner_name", "卓太航");
        ::setup();
}
